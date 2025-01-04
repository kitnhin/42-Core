#ifndef SOCKET_HPP
#define SOCKET_HPP

#include "webserv.hpp"

using std::string;

class Socket
{
	private:
		int	sock_fd;
		Request request;

	public:
	int	setup_socket(string host, string port, struct addrinfo *reso);
	Socket();
	~Socket();

	static vector<struct pollfd> poll_socket_fds;
	static vector<int> listen_socket_fds;
	static vector<Socket> io_connections;
	void	add_new_socket_to_poll(int fd, int ev);
	void	process_req(vector<std::pair<int, struct addrinfo> > &sockets_addrinfo);
	Request	get_req();
	void	receive_data(Socket socket);
	
	void	set_sock_fd(int sockfd);
	int		get_io_connection(int fd);
	std::string generate_http_response(const std::string &file_path);
};

#endif