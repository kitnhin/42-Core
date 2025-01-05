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

std::map<string, string> &Server::get_error_pages()
{
	return this->error_pages;
}

string Server::get_client_max_body_size()
{
	return this->client_max_body_size;
}
std::vector<Location> &Server::get_location()
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

void Server::set_get_location(std::vector<Location> location)
{
    this->location = location;
}

std::vector<std::pair<std::string, std::string> > Server::socket_addr; // need this for definition cannot just put inside header it wont compile rip

void	print_server(Server &server)
{
    cout << "=======================================" << std::endl;
    cout << "Server Details:" << std::endl;
    cout << "Host: " << server.get_host() << std::endl;
    cout << "Port: " << server.get_port() << std::endl;
    cout << "Server Name: " << server.get_server_name() << std::endl;
    cout << "Client Body Size: " << server.get_client_max_body_size() << std::endl;

	cout << endl;
    cout << "Error Pages:" << std::endl;
	std::map<string,string> error_pages= server.get_error_pages();
    for (std::map<string,string>::iterator it = error_pages.begin(); it != error_pages.end(); it++)
        cout << "Error Code: " << it->first << " -> Page: " << it->second << std::endl;
	
	cout << endl;
	cout << "Locations: " << endl;
	for (std::vector<Location>::iterator it = server.get_location().begin(); it != server.get_location().end(); it++)
		it->print_location();

    cout << "=======================================" << std::endl;
}