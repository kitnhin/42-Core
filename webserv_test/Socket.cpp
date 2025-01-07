#include "Socket.hpp"

Socket::Socket() {}

Socket::~Socket() {}

// Define static member variables
std::vector<Socket> Socket::io_connections;
std::vector<struct pollfd> Socket::poll_socket_fds;
std::vector<int> Socket::listen_socket_fds;

Request &Socket::get_req()
{
	return this->request;
}

void	Socket::set_sock_fd(int sockfd)
{
	this->sock_fd = sockfd;
}

int	Socket::setup_socket(string host, string port, struct addrinfo *reso)
{
	int				sockfd;
	struct addrinfo	hints; //for getaddrinfo later

	//init hint struct
	memset(&hints, 0, sizeof(hints));
	//fill in these so getaddrinfo can return the resolved addresses for these requirements(the rest will be auto filled in by getinfoaddr)
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = 0; //0 means we let getaddrinfo auto decide
	hints.ai_flags = AI_NUMERICSERV;

	//getaddrinfo
	if(getaddrinfo(host.c_str(), port.c_str(), &hints, &reso) < 0)
		throw CustomException("Error: getaddrinfo failed");

	//create socket
	if((sockfd = socket(reso->ai_family, reso->ai_socktype, reso->ai_protocol)) < 0)
		throw CustomException("Error: Socket creation failed");

	//set socket options (so we can bind without time delay after socket is closed)
	int opt = 1;
	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
		throw CustomException("Setsockopt failure: " + std::string(strerror(errno)));
	
	//bind socket
	if(bind(sockfd, reso->ai_addr, reso->ai_addrlen) < 0)
	{
		close(sockfd);
		throw CustomException("Error: Bind socket failed");
	}

	//mark socket as listening socket
	if(listen(sockfd, LISTEN_BACKLOG) < 0)
	{
		close(sockfd);
		throw CustomException("Error: Listen socket failed");
	}
	
	//final stuffs
	cout << "Listening on port: " << port << "...." << endl;
	listen_socket_fds.push_back(sockfd);
	return(sockfd);
}

//notes:
//AF_INET is to specift ipv4 socket
//SOCK_STREAM is to specify TCP
//AI_NUMERICSERV tells getaddrinfo to treat the port as numbers instead of service names (such as http, where equates to port 80)

//getaddrinfo inserts a resolved address linked list (reso) which contains the information about addresses that fit our requirements (the hints we inserted)
//lets say we type host is localhost, then it returns a linked list fill wif information abt addresses wif 127.0.0 (for IPv4) 
//after that we can use the information in the struct it returns to help us create and bind our sockets.

void	Socket::add_new_socket_to_poll(int fd, int ev)
{
	struct pollfd newfd;

	newfd.fd = fd;
	newfd.events = ev;
	poll_socket_fds.push_back(newfd);
}

//need to specially close not just the fd but everything abt it especially the ioconnection part;
//cuz the io connection part has information abt the request previously
//so if we only close the fd without closing this, when we open again the previous request will be used,
//hence causing the next fd u open will have the same request
//lets say we accepted fd 5, send the response, and close ONLY THE FD
//the ioconnection isnt removed, so the next time we accept again wif fd 5, we will end up using the old socket object in ioconnections
void Socket::close_fd(int fd, int fd_index)
{
	io_connections.erase(get_io_connection(fd) + io_connections.begin());
	poll_socket_fds.erase(poll_socket_fds.begin() + fd_index);
	close(fd);
}

int	Socket::get_io_connection(int fd)
{
	for(size_t i = 0; i < io_connections.size(); i++)
	{
		if(io_connections[i].sock_fd == fd)
			return i;
	}
	throw CustomException("Error: cannot find io connection");
	return -1;
}

void	Socket::update_fd_event(int fd, int ev)
{
	for(size_t i = 0; i < poll_socket_fds.size(); i++)
	{
		if(poll_socket_fds[i].fd == fd)
			poll_socket_fds[i].events = ev;
	}
}
// New function to generate HTTP response
std::string Socket::generate_http_response(const std::string &file_path)
{
    // Open the HTML file with the read-only flag
    int file_fd = open(file_path.c_str(), O_RDONLY);  // Path to your HTML file
    if (file_fd == -1) {
        std::cerr << "Error: Unable to open HTML file." << std::endl;
        throw CustomException("Unable to open HTML file");
    }

    // Create a buffer to store the content (using a fixed size for simplicity)
    char htmlbuffer[4096];  // You can adjust the size of this buffer
    std::string html_content;
    ssize_t bytes_read;

    // Read the content in chunks and append it to the string
    while ((bytes_read = read(file_fd, htmlbuffer, sizeof(htmlbuffer))) > 0) {
        html_content.append(htmlbuffer, bytes_read);
    }

    // Error check for read
    if (bytes_read == -1) {
        std::cerr << "Error: Unable to read the file." << std::endl;
        close(file_fd);
        throw CustomException("Unable to read the HTML file");
    }

    // Clean up: Close the file
    close(file_fd);

    // HTTP Response headers
    std::string response = "HTTP/1.1 200 OK\r\n";
    response += "Content-Type: text/html\r\n";
    response += "Content-Length: " + std::to_string(html_content.length()) + "\r\n";
    response += "\r\n";  // End of headers

    // Append the HTML content
    response += html_content;

    return response;
}

void	Socket::receive_data(Socket &socket)
{
	char buffer[10000] = {0}; //HARDCODE AH
	size_t bytes_received = recv(socket.sock_fd, buffer, sizeof(buffer) - 1, 0);
	//cout << "bytes received: " << bytes_received << endl;
	if(bytes_received > 0) //reminds me of gnl exam haih so gay
	{
		buffer[bytes_received] = '\0';
		//cout << "Received from client (FD " << socket.sock_fd << " ) : " << buffer << endl;
	}
	else if(bytes_received < 0)
		throw CustomException("Error: recv failed");
	socket.get_req().set_data(socket.get_req().get_data().append(buffer, bytes_received));
	socket.get_req().parse_request_data_main();
	//print_request(socket.get_req());
}

//important note, never use "this" here
void	Socket::process_req(vector<pair<int, struct addrinfo> > &sockets_addrinfo, vector<Server>Servers)
{
	//find the port that has a req
	for(size_t i = 0; i < poll_socket_fds.size(); i++)
	{
		if(poll_socket_fds[i].revents & POLLIN)
		{
			if(std::find(listen_socket_fds.begin(), listen_socket_fds.end(), poll_socket_fds[i].fd) != listen_socket_fds.end())
			{
				struct addrinfo *res;
				Socket connection_socket;
				int accept_socket_fd;
				res = NULL;
				for(size_t i = 0; i < sockets_addrinfo.size(); i++)
				{
					if(sockets_addrinfo[i].first == poll_socket_fds[i].fd)
					{
						res = &(sockets_addrinfo[i].second);
						break;
					}
				}
				if(res == NULL)
					throw CustomException("Error: can't find socket addinfo");
				if((accept_socket_fd = accept(poll_socket_fds[i].fd,  (struct sockaddr*) &res->ai_addr, &res->ai_addrlen)) <= 0)
					throw CustomException("Error: accept socket failed");
				
				//add accept socket to our new connection
				connection_socket.set_sock_fd(accept_socket_fd);
				io_connections.push_back(connection_socket);

				//add accept socket to poll
				add_new_socket_to_poll(accept_socket_fd, POLLIN);
			}
			else
			{
				int connect_index = get_io_connection(poll_socket_fds[i].fd);
				receive_data(io_connections[connect_index]);
				update_fd_event(poll_socket_fds[i].fd, POLLIN | POLLOUT); // need to update here instead of when accept() returns the socket if not will have error
			}
		}
		else if (poll_socket_fds[i].revents & POLLOUT)
		{
			int connect_index = get_io_connection(poll_socket_fds[i].fd);
			Socket socket = io_connections[connect_index];
			if(socket.get_req().get_req_data().length() <= 0)
				throw CustomException("Error: no request found");
			this->response.main_response_function(socket.get_req(), Servers);
			send(socket.sock_fd, this->response.get_response_data().c_str(), this->response.get_response_data().size(), 0);
			close_fd(poll_socket_fds[i].fd, i); //see explanation in function
		}
	}
}
