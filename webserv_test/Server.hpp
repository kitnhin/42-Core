#ifndef SERVER_HPP
#define SERVER_HPP

#include "webserv.hpp"

using std::string;

class Server
{
	private:
		string host;
		string port;
		string server_name;
		std::map<string, string> error_pages;
		string client_max_body_size;
		std::vector<string> location;

	public:
		Server();
		~Server();
		string get_host();
		string get_port();
		string get_server_name();
		std::map<string, string> get_error_pages();
		string get_client_max_body_size();
		std::vector<string> get_location();

		void	set_host(string host);
		void	set_port(string port);
		void	set_server_name(string server_name);
		void	set_error_pages(std::map<string, string> error_pages);
		void	set_client_max_body_size(string client_body_size);
		void	set_get_location(std::vector<string> location);
};


#endif