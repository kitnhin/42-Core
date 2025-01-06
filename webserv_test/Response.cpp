#include "Response.hpp"

Response::Response() {}

Response::~Response() {}

void	Response::set_response(string newResponse)
{
	this->response_data = newResponse;
}

string	Response::get_response_data()
{
	return this->response_data;
}

string	Response::get_start_line(Request request, string code, Server &server)
{
	(void)server;
	string start_line = request.get_http_ver() + " " + code + " " + get_code_string(code) + "\r\n";
	return start_line;
}

string	Response::get_code_string(string code)
{
	if(code == "200")
		return ("OK");
	if(code == "403")
		return("Forbidden");
	if(code == "404")
		return("Not found");
	if(code == "405")
		return("Method not allowed");

	return("Unknown Error");
}

Server	&Response::find_server(Request request, vector<Server>& Servers)
{
	for(size_t i = 0; i < Servers.size(); i++)
	{
		if(request.get_port() == Servers[i].get_port())
			return Servers[i];
	}
	throw CustomException("Error: cannot find respective server");
}

string	Response::get_error_page(string error_code, Server &server)
{
	string error_page_contents;
	string buffer;
	for(std::map<string, string>::iterator it = server.get_error_pages().begin(); it != server.get_error_pages().end(); it++)
	{
		if(it->first == error_code)
		{
			string filepath = "." + it->second;
			std::ifstream infile(filepath);
			if(!infile.is_open())
				throw CustomException("Error: cannot open error file");
			while(getline(infile, buffer))
				error_page_contents.append(buffer);
		}
	}
	return error_page_contents;
}

string	Response::get_headers(string content)
{
	string res = "Content-Type: text/html\r\nContent-Length: " + std::to_string(content.size()) + "\r\nConnection: keep-alive\r\n\r\n";
	return res;
}

void	Response::handle_error(Request request, string error_code, Server &server)
{
	string start_line = get_start_line(request, error_code, server);
	string error_page_contents = get_error_page(error_code, server);
	if(error_page_contents == "")
	{
		error_page_contents += "<!DOCTYPE html>";
		error_page_contents += "<head>";
		error_page_contents += "<title>" + get_code_string(error_code) + "</title>";
		error_page_contents += "</head>";
		error_page_contents += "<body>";
		error_page_contents += "<center>";
		error_page_contents += "<h1>" + error_code + " " + get_code_string(error_code) + "</h1>";
		error_page_contents += "</center>";
		error_page_contents += "</body>";
		error_page_contents += "</html>";
	}
	string headers = get_headers(error_page_contents);
	this->response_data = start_line + headers + error_page_contents;
}

void	Response::handle_get(Request request, Server &server)
{
	handle_error(request, "404", server); //try throwing error regardless
}

void	Response::handle_post(Request request, Server &server)
{
	handle_error(request, "404", server); //try throwing error regardless
}

void	Response::handle_delete(Request request, Server &server)
{
	handle_error(request, "404", server); //try throwing error regardless
}

void	Response::main_response_function(Request request, vector<Server> &Servers)
{
	Server &respective_server = find_server(request, Servers);
	if(request.get_method() == "GET")
		handle_get(request, respective_server);
	else if(request.get_method() == "POST")
		handle_post(request, respective_server);
	else if(request.get_method() == "DELETE")
		handle_delete(request, respective_server);
	else
		handle_error(request, "405", respective_server);
}