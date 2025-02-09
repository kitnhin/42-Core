#ifndef HTTP_HPP
#define HTTP_HPP

#include "webserv.hpp"
#include "Server.hpp"

class Server;

class HTTP
{
	private:
		std::vector<Server> Servers;
		std::vector<std::pair<int, struct addrinfo> > all_sockets_list; //maybe couldve used map instead but sui bian la meng seong used this lol
	public:
	HTTP();
	~HTTP();
	std::vector<Server> &get_servers();
	std::vector<std::pair<int, struct addrinfo> > &get_all_sockets_list();
	void	poll_loop();


	void	_run_webserv(char **argv);
};


#endif
