#include "HTTP.hpp"

HTTP::HTTP() {}

HTTP::~HTTP() {}

std::vector<Server> &HTTP::get_servers()
{
	return(this->Servers);
}

void	HTTP::_run_webserv(char **argv)
{
	Config config(static_cast<string>(argv[1]));
	Socket sock;

	//parsing
	config.main_parse_function(Servers);
	
	//setting up sockets
	vector<pair<int, struct addrinfo> > sockets; //maybe couldve used map instead but sui bian la meng seong used this lol
	for(vector<pair<string, string> >::iterator it = Server::socket_addr.begin(); it != Server::socket_addr.end(); it++)
	{
		int sockfd;
		struct addrinfo reso;
		sockfd = sock.setup_socket(it->first, it->second, &reso);
		sock.add_new_socket_to_poll(sockfd, POLLIN);
		sockets.push_back(std::make_pair(sockfd, reso));
	}

	//PRINTTTTT
	for(size_t i = 0; i < sock.poll_socket_fds.size(); i++)
		cout << "Poll sockets: " << sock.poll_socket_fds[i].fd <<endl;
	
	//main loop that waits for connections and process it
	int poll_status;
	while(1)
	{
		poll_status = poll(sock.poll_socket_fds.data(), sock.poll_socket_fds.size(), -1);//poll will always be 0 if nth is detected, -1 to tell poll to wait infinitely wif no max time
		if(poll_status == 0)
			continue;
		else if (poll_status < 0)
			throw CustomException("Error: poll error");
		else
			sock.process_req(sockets, Servers);
	}
}