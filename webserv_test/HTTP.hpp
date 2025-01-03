#ifndef HTTP_HPP
#define HTTP_HPP

#include "webserv.hpp"
#include "Server.hpp"

class Server;

class HTTP
{
	private:
		std::vector<Server> Servers;
	public:
	HTTP();
	~HTTP();
	std::vector<Server> &get_servers();

	void	_run_webserv(char **argv);
};


#endif
