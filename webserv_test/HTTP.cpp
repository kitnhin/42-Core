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

	//parsing
	config.main_parse_function(Servers);
	for(vector<pair<string, string> >::iterator it = Server::socket_addr.begin(); it != Server::socket_addr.end(); it++)
		cout << "socket host : " << it->first << " socket port: " << it->second << endl;
	
	//setting up sockets
	vector<pair<int, struct addrinfo> > sockets; //maybe couldve used map instead but sui bian la meng seong used this lol
	for(vector<pair<string, string> >::iterator it = Server::socket_addr.begin(); it != Server::socket_addr.end(); it++)
	{
		int sockfd;
		struct addrinfo sock_info;

		sockfd = 
	}
}