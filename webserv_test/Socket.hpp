#ifndef SOCKET_HPP
#define SOCKET_HPP

#include "webserv.hpp"

using std::string;

class Request;
class Location;

class Response //include this here first cuz somehow incomplete type
{
	private:
		string response_data;

	public:
		Response();
		~Response();
		void	set_response(string newResponse);
		string	get_response_data();

		void	main_response_function(Request request, vector<Server> &Servers);

		void	generate_autoindex_page(Request request, Server &server, Location &location);
		string	get_file_type(string path);
		string	parse_resources(string path);
		string	get_file_size(size_t filesize);
		string	get_start_line(Request request, string code, Server &server);
		string	get_full_resource_path(Request request, Location &location);
		string	urlDecode(string &str);
		string	get_code_string(string error_code);
		string	get_error_page(string error_code, Server &server);
		Location *get_location(Request request, Server &server);
		int		check_allowed_methods(string method, Location &location);
		string	get_headers(string content, string content_type);
		void	handle_get(Request request, Server &server);
		void	handle_post(Request request, Server &server);
		void	handle_delete(Request request, Server &server);
		void	handle_error(Request request, string error_code, Server &server);
		void	handle_return(Request request, Server &server, Location &location);
		void	handle_autoindex(Request request, Server &server, Location &location, string req_path);
		Server	&find_server(Request request, vector<Server> &Servers);
};

class Socket
{
	private:
		int	sock_fd;
		Request request;
		Response response;

	public:
		int	setup_socket(string host, string port, struct addrinfo *reso);
		Socket();
		~Socket();

		static vector<struct pollfd> poll_socket_fds;
		static vector<int> listen_socket_fds;
		static vector<Socket> io_connections;

		void	add_new_socket_to_poll(int fd, int ev);
		void	process_req(vector<std::pair<int, struct addrinfo> > &sockets_addrinfo, vector<Server>Servers);
		Request	&get_req();
		void	receive_data(Socket &socket);
		void	update_fd_event(int fd, int ev);
		void	set_sock_fd(int sockfd);
		int		get_io_connection(int fd);
		std::string generate_http_response(const std::string &file_path);
		void	close_fd(int fd, int fd_index);
};

#endif