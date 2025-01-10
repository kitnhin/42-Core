#ifndef CGI_HPP
#define CGI_HPP

#include "webserv.hpp"

using std::string;

class Response;

class Cgi
{
	private: 

	public:
	Cgi();
	~Cgi();
	void		Cgi_main(Request &request, Response &response, Location &location, Server &server);
	char 	**config_env(Request &request);
	string	get_cgi_output(int pipefd);
};

#endif