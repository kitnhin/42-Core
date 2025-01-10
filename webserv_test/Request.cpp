#include "Request.hpp"

Request::Request() {}

Request::~Request() {}

//get

string	Request::get_req_data()
{
	return this->req_data;
}

string	Request::get_method()
{
	return this->method;
}

string	Request::get_target()
{
	return this->target;
}

string	Request::get_http_ver()
{
	return this->http_ver;
}

string	Request::get_host()
{
	return this->host;
}

string	Request::get_port()
{
	return this->port;
}

string	Request::get_content_length()
{
	return this->content_length;
}

std::map<string, string>	&Request::get_header_fields()
{
	return this->header_fields;
}

string	Request::get_body()
{
	return this->body;
}

string Request::get_data()
{
	return this->req_data;
}

void Request::set_data(string newdata)
{
	this->req_data = newdata;
}

void Request::parse_request_line(size_t &pos)
{
	size_t temp;
	temp = req_data.find_first_of(" \t", pos);
	this->method = req_data.substr(pos, temp - pos);
	pos = temp + 1;
	temp = req_data.find_first_of(" \t", pos);
	this->target = req_data.substr(pos, temp - pos);
	pos = temp + 1;
	temp = req_data.find_first_of("\r", pos);
	this->http_ver = req_data.substr(pos, temp - pos);
	pos = temp + 2;
	// if(method.length() == 0 || target.length() == 0 || http_ver.length() == 0)
	// 	throw CustomException("Error: Request error");
}

void Request::parse_host_port(string str)
{
	//extract host
	size_t temp;
	temp = str.find_first_of(":", 0);
	this->host = str.substr(0, temp);

	//extract port
	this->port = str.substr(temp + 1, str.length() - temp);
}


void Request::parse_header_fields(size_t &pos)
{
	size_t temp;
	std::pair <string, string> pair;
	while(pos < req_data.length() && req_data[pos] != '\r') // second condition is to check for last line
	{
		temp = req_data.find_first_of(":" , pos);
		pair.first = req_data.substr(pos, temp - pos);
		pos = temp + 2;
		temp = req_data.find_first_of("\r", pos); //mengseong used /n but i thot the header fields end wif /r/n
		pair.second = req_data.substr(pos, temp - pos);
		pos = temp + 2;
		if(pair.first == "Host")
			parse_host_port(pair.second);
		if(pair.first == "Content-Length")
			this->content_length = pair.second;
		this->header_fields.insert(pair);
	}
}

void Request::parse_body(size_t &pos, int socket_fd)
{
	string entire_body;
	if(content_length.length() == 0)
		return ;
	unsigned long long contentlen = std::stoll(content_length);
	cout << "\n\n__________________________________" << endl;
	cout << "CONTENTLENGTH: " << contentlen << endl;

	//first read
	char buffer1[contentlen + 1];
	int bytesread1 = recv(socket_fd, buffer1, contentlen, 0);
	buffer1[bytesread1] = '\0';
	cout << "bytesread1: " << bytesread1 << endl;
	entire_body += buffer1;

	//second read
	char buffer2[contentlen - bytesread1 + 1];
	int bytesread2 = recv(socket_fd, buffer2, contentlen, 0);
	buffer2[bytesread2] = '\0';
	cout << "bytesread2: " << bytesread2 << endl;
	entire_body += buffer2;

	//third read
	char buffer3[contentlen - bytesread2 - bytesread1 + 1];
	int bytesread3 = recv(socket_fd, buffer3, contentlen, 0);
	buffer3[bytesread3] = '\0';
	cout << "bytesread3: " << bytesread3 << endl;
	entire_body += buffer3;
	this->body = entire_body;
	cout << "BODY: " << endl;
	cout << this->body << endl;
}

void Request::parse_request_data_main(int socket_fd)
{
	size_t pos = 0;
	parse_request_line(pos);
	parse_header_fields(pos);
	parse_body(pos, socket_fd);
}

void	print_request(Request request)
{
	std::cout << "REQUEST ATTRIBUTES" << std::endl;
	std::cout << "==================" << std::endl;
	std::cout << "method: " << request.get_method() << std::endl;
	std::cout << "route: " << request.get_target() << std::endl;
	std::cout << "http_protocol: " << request.get_http_ver() << std::endl;
	std::cout << "host: " << request.get_host() << std::endl;
	std::cout << "port: " << request.get_port() << std::endl;
	std::cout << "content_length: " << request.get_content_length() << std::endl;
	std::map<std::string, std::string> header_fields = request.get_header_fields();
	std::map<std::string, std::string>::iterator it = header_fields.begin();
	std::map<std::string, std::string>::iterator ite = header_fields.end();
	std::cout << std::endl;
	std::cout << "Header fields" << std::endl;
	std::cout << "-------------" << std::endl;
	for (; it != ite; it++)
	{
		std::cout << it->first << ":" << it->second << std::endl;
	}
	std::cout << "-------------" << std::endl;
	std::cout << "Message Body" << std::endl;
	std::cout << request.get_body() << std::endl;
	std::cout << "==================" << std::endl;
}