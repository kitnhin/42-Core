#include "Server.hpp"

Server::Server() {}

Server::~Server() {}

string Server::get_host()
{
	return this->host;
}

string Server::get_port()
{
	return this->port;
}

string Server::get_server_name()
{
	return this->server_name;
}

std::map<string, string> Server::get_error_pages()
{
	return this->error_pages;
}

string Server::get_client_max_body_size()
{
	return this->client_max_body_size;
}

std::vector<string> Server::get_location()
{
	return this->location;
}
	
void	Server::set_host(string host)
{
	this->host = host;
}

void Server::set_port(string port)
{
    this->port = port;
}

void Server::set_server_name(string server_name)
{
    this->server_name = server_name;
}

void Server::set_error_pages(std::map<string, string> error_pages)
{
    this->error_pages = error_pages;
}

void Server::set_client_max_body_size(string client_body_size)
{
    this->client_max_body_size = client_body_size;
}

void Server::set_get_location(std::vector<string> location)
{
    this->location = location;
}
