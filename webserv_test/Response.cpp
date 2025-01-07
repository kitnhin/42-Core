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
	if(code == "301")
		return("Moved Permenantly");
	if(code == "302")
		return ("Found");
	if(code == "307")
		return ("Temporary Redirect");
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

Location *Response::get_location(Request request, Server &server)
{
	int relative_match_index = 0;
	int relative_match_flag = 0;
	int current_index = 0;
	for(vector<Location>::iterator it = server.get_location().begin(); it != server.get_location().end(); it++)
	{
		if(it->get_path() == request.get_target())
			return(&(*it));
		if(it->get_path() == request.get_target().substr(0, it->get_path().length()) && relative_match_flag == 0)
		{
			relative_match_index = current_index;
			relative_match_flag = 1;
		}
		current_index++;
	}
	if(relative_match_flag == 1)
		return (&(server.get_location()[relative_match_index]));
	return NULL;
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

int		Response::check_allowed_methods(string method, Location &location)
{
	for(vector<string>::iterator it = location.get_allowed_methods().begin(); it != location.get_allowed_methods().end(); it++)
	{
		if(*it == method)
			return 1;
	}
	return 0;
}

void	Response::handle_return(Request request, Server &server, Location &location)
{
	string return_ = location.get_return();
	size_t pos = 0;
	string status_code;
	size_t temp;
	while(return_[pos] == ' ' || return_[pos] == '\t')
		pos++;
	if(std::isdigit(return_[pos]))
	{
		temp = return_.find_first_of(" \t");
		if(temp == std::string::npos)
			throw CustomException("Error: invalid return part");
		status_code = return_.substr(pos, temp - pos);
		pos = temp + 1;
	}
	else
		status_code = "302";
	while(return_[pos] == ' ' || return_[pos] == '\t')
		pos++;
	string path = return_.substr(pos, return_.size() - pos);

	this->response_data += get_start_line(request, status_code, server);
	this->response_data += "Location: " + path + "\r\n" + get_headers("");
	//surprisingly this one dn code the website can just change the location to the path then it will move u there liao wth
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
	Location *location = get_location(request, server);
	if(!location)
		handle_error(request, "404", server);
	else if(check_allowed_methods("GET", *location) == 0)
		handle_error(request, "405", server);
	else if(location->get_return() != "")
		handle_return(request, server, *location);
	else
		handle_error(request, "201", server); //use this to print webpage first i havent code the others yet
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