#ifndef SOCKET_HPP
#define SOCKET_HPP

#include "webserv"

using std::string

class Socket
{
	public:

	int	setup_socket(string host, string port, struct addrinfo sock_info);
};

#endif