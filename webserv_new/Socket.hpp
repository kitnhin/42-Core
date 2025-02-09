#ifndef SOCKET_HPP
#define SOCKET_HPP

#include "webserv.hpp"

using std::string;

class Location;

class Request
{
	private:
		string req_data;
		//parts of the request
		string method;
		string target;
		string http_ver;
		string host;
		string port;
		string content_length;
		std::map<string, string> header_fields;
		string body;

	public:
		Request();
		~Request();
		string	get_data();
		void	set_data(string newdata);

		//get
		string	get_req_data();
		string	get_method();
		string	get_target();
		string	get_http_ver();
		string	get_host();
		string	get_port();
		string	get_content_length();
		std::map<string, string> &get_header_fields();
		string	get_body();


		//parsing
		void	parse_request_data_main(int socket_fd);
		void	parse_request_line(size_t &pos);
		void	parse_header_fields(size_t &pos);
		void	parse_body(size_t &pos, int socket_fd);
		void	parse_host_port(string str);
};

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

		void	do_indexing(Request request, Server &server, Location *location, string resource_path);
		void	get_file_contents(Request request, Server &server, string resource_path);

		void	handle_get(Request request, Server &server);
		void	handle_post(Request request, Server &server);
		void	handle_delete(Request request, Server &server);
		void	handle_error(Request request, string error_code, Server &server);
		void	handle_return(Request request, Server &server, Location &location);
		void	handle_autoindex(Request request, Server &server, Location &location, string req_path);

		string	get_error_page(string error_code, Server &server);
		string	get_start_line(Request request, string code, Server &server);
		string	get_file_type(string path);
		string	parse_resources(string path);
		string	get_full_resource_path(Request request, Location &location);
		string	urlDecode(string &str);
		string	get_code_string(string error_code);
		Location *get_location(Request request, Server &server);
		int		check_allowed_methods(string method, Location &location);
		string	get_headers(string content, string content_type);
		Server	&find_server(Request request, vector<Server> &Servers);
		int		check_request_body_valid(Request &request);
};

class Socket
{
	private:
		int	sock_fd;
		Request request;
		Response response;

	public:
		Socket();
		~Socket();

		static vector<struct pollfd> poll_socket_fds;
		static vector<int> listen_socket_fds;
		static vector<Socket> io_connections;

		//get
		Request	&get_req();

		//setup socket
		void	main_setup_socket(vector<std::pair<int, struct addrinfo> > &all_sockets_list);
		int	setup_socket(string host, string port, struct addrinfo *reso);

		//request stuff
		void	receive_data(Socket &socket);
		void	process_req_POLLIN_connection_socket(int i);
		void	process_req_POLLIN_listen_socket(int i, vector<std::pair<int, struct addrinfo> > &sockets_addrinfo);
		void	process_req_POLLOUT(int i, vector<Server> Servers); //output stuff and close socket
		void	process_req(vector<std::pair<int, struct addrinfo> > &sockets_addrinfo, vector<Server>Servers);

		//utils
		void	add_new_socket_to_poll(int fd, int ev);
		void	update_fd_event(int fd, int ev);
		void	set_sock_fd(int sockfd);
		int		get_io_connection(int fd);
		void	close_fd(int fd, int fd_index);
};

#endif