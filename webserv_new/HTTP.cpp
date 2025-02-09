#include "HTTP.hpp"

HTTP::HTTP() {}

HTTP::~HTTP() {}

std::vector<Server> &HTTP::get_servers()
{
	return(this->Servers);
}

std::vector<pair<int, struct addrinfo> > &HTTP::get_all_sockets_list()
{
	return(this->all_sockets_list);
}

void	HTTP::poll_loop()
{
	int poll_status;
	Socket sock;
	while(1)
	{
		poll_status = poll(sock.poll_socket_fds.data(), sock.poll_socket_fds.size(), -1);//poll will always be 0 if nth is detected, -1 to tell poll to wait infinitely wif no max time
		if(poll_status == 0)
			continue;
		else if (poll_status < 0)
			throw std::runtime_error("Error: poll error");
		else
			sock.process_req(this->all_sockets_list, Servers);
	}
}

void	HTTP::_run_webserv(char **argv)
{
	Config config(static_cast<string>(argv[1]));
	Socket sock;

	//parsing
	config.main_parse_function(Servers);
	
	//setting up sockets
	sock.main_setup_socket(this->all_sockets_list);
	
	//main loop that waits for connections and process it
	poll_loop();
}