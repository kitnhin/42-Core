#ifndef CONFIG_HPP
#define CONFIG_HPP

#include "webserv.hpp"
#include "Server.hpp"

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::pair;

class Server;

class Config
{
	private:
		std::string file_path;
		std::string file_data;

	public:
		Config(std::string path);
		void	readfile(); // Move to private
		void	skip_whitespaces(size_t &pos);
		void	parse_server_block(size_t &pos, std::vector<Server> &server_list);
		void	main_parse_function(std::vector<Server> &server_list);

		void	parse_listen_part(size_t &pos, Server &server);
		void	parse_server_name_part(size_t &pos, Server &server);
		void	parse_client_body_size(size_t &pos, Server &server);
		void	parse_error_pages(size_t &pos, Server &server);
		void	parse_socket_addr(Server &server);
};	

#endif