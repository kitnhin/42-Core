#ifndef CONFIG_HPP
#define CONFIG_HPP

#include "webserv.hpp"
#include "Server.hpp"

using std::string;
using std::cout;
using std::endl;

class Server;

class Config
{
	private:
		std::string file_path;
		std::string file_data;

	public:
		Config(std::string path);
		void	readfile();
		void	skip_whitespaces(size_t &pos);
		void	parse_server_block(size_t &pos, std::vector<Server> &server_list);
		void	main_parse_function(std::vector<Server> &server_list);

		void	parse_listen_part(size_t &pos, Server &server);
};	

#endif