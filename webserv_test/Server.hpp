#ifndef SERVER_HPP
#define SERVER_HPP

#include "webserv.hpp"

using std::string;
using std::vector;

class Location;

class Server
{
	private:
		string host;
		string port;
		string server_name;
		std::map<string, string> error_pages;
		string client_max_body_size;
		std::vector<Location> location;

	public:
		Server();
		~Server();
		string get_host();
		string get_port();
		string get_server_name();
		std::map<string, string> &get_error_pages(); //need to put reference if not i cant assign values to it
		string get_client_max_body_size();
		std::vector<Location> &get_location();

		void	set_host(string host);
		void	set_port(string port);
		void	set_server_name(string server_name);
		void	set_error_pages(std::map<string, string> error_pages);
		void	set_client_max_body_size(string client_body_size);
		void	set_get_location(std::vector<Location> location);

		static vector<std::pair<string, string> > socket_addr; //to keep track of all the sockets we need to monitor
};

void	print_server(Server &server);

#endif