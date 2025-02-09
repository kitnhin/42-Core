#include "Response.hpp"

static std::string my_itoa(size_t i){
	std::string s;
	std::stringstream out;
	out << i;
	s = out.str();
	return s;
}

static int my_atoi(std::string s) {
	int i;
	std::istringstream(s) >> i;
	return i;
}

static int my_hex_to_int(std::string s) {
	int i;
	std::stringstream ss;
	ss << std::hex << s;
	ss >> i;
	return i;
}

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
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////response making helpers/////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

string	Response::get_start_line(Request request, string code, Server &server)
{
	(void)server;
	string start_line = request.get_http_ver() + " " + code + " " + get_code_string(code) + "\r\n";
	return start_line;
}

string	Response::get_headers(string content, string content_type)
{
	string res = "Content-Type: " + content_type + "\r\nContent-Length: " + my_itoa(content.size()) + "\r\nConnection: keep-alive\r\n\r\n";
	return res;
}


////////////////////////////////////////////////
//////////////////error stuffs//////////////////
////////////////////////////////////////////////

string	Response::get_error_page(string error_code, Server &server)
{
	string error_page_contents;
	string buffer;
	for(std::map<string, string>::iterator it = server.get_error_pages().begin(); it != server.get_error_pages().end(); it++)
	{
		if(it->first == error_code)
		{
			string filepath = "." + it->second;
			std::ifstream infile(filepath.c_str());
			if(!infile.is_open())
				throw std::runtime_error("Error: cannot open error file");
			while(getline(infile, buffer))
				error_page_contents.append(buffer);
		}
	}
	return error_page_contents;
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
		error_page_contents += "<h1> Error: " + error_code + " " + get_code_string(error_code) + "</h1>";
		error_page_contents += "</center>";
		error_page_contents += "</body>";
		error_page_contents += "</html>";
	}
	string headers = get_headers(error_page_contents, "text/html");
	this->response_data = start_line + headers + error_page_contents;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////indexing////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


void	Response::do_indexing(Request request, Server &server, Location *location, string resource_path)
{
	string file_contents;
	vector<string>::iterator it = location->get_index().begin();
	vector<string>::iterator ite = location->get_index().end();
	while(it != ite)
	{
		if(file_contents == "")
			file_contents = parse_resources(resource_path + *it);
		if(file_contents == "")
			it++;
		else
			break;
	}
	if(file_contents != "")
		this->response_data = get_start_line(request, "200", server) + get_headers(file_contents, get_file_type(resource_path + *it)) + file_contents;
	else if(location->get_autoindex() == true)
		handle_autoindex(request, server, *location, resource_path);
	else
		handle_error(request, "404", server);
}

void	Response::handle_autoindex(Request request, Server &server, Location &location, string path)
{
	if(location.get_autoindex() == true)
	{
		DIR *dir = opendir(path.c_str());
		if(!dir)
			handle_error(request, "403", server);
		else
		{
			string response_body;
			string dir_name = path.substr(1, path.length() - 1); // to remove the slash
			autoindex auto_index;

			auto_index.generate_autoindex_page_first_part(response_body, dir_name); //generate the top part of the html page (styling, headers....)
			auto_index.generate_autoindex_page_second_part(response_body, dir, path); //generate the body part (readdir and listing the filees)

			this->response_data = get_start_line(request, "200", server) + get_headers(response_body, "text/html") + response_body;
		}
	}
	else
		handle_error(request, "404", server);
}
///////////////////////////////////////////////////////////////////////////
///////////////////////////getting file contents///////////////////////////
///////////////////////////////////////////////////////////////////////////

string	Response::parse_resources(string path)
{
	string res;
	string buffer;
	std::ifstream infile(path.c_str());
	if(!infile.is_open())
		return "";
	while(getline(infile, buffer))
		res += buffer;
	return res;
}

string	Response::get_file_type(string path)
{
	size_t dotpos = path.find_first_of(".", 1);
	if(dotpos == std::string::npos)
		return("plain/text");
	string type = path.substr(dotpos + 1, path.length() - dotpos - 1);

	if(type == "html")
		return "text/html"; //cannot reverse the order if not will have some weird behaviour
	else if (type == "css")
		return "text/css";
	else if (type == "js")
        return "text/javascript";
	else if (type == "jpeg" || type == "jpg")
		return "image/jpeg";
	else if (type == "png")
		return "image/png";
	else if (type == "gif")
		return "image/gif";
	else if (type == "txt")
		return "text/plain";
	else
		return "text/plain";
}

void	Response::get_file_contents(Request request, Server &server, string resource_path)
{
	string file_contents = parse_resources(resource_path);
	if(file_contents == "")
		handle_error(request, "404", server);
	else
		this->response_data = get_start_line(request, "200", server) + get_headers(file_contents, get_file_type(resource_path)) + file_contents;
}

/////////////////////////////////////////////////////////////////////
/////////////////////////handle methods fts//////////////////////////
/////////////////////////////////////////////////////////////////////

void	Response::handle_get(Request request, Server &server)
{
	Location *location = get_location(request, server);
	Cgi cgi;

	if(!location)
		handle_error(request, "403", server);
	else if(check_allowed_methods("GET", *location) == 0)
		handle_error(request, "405", server);
	else if(location->get_return() != "")
		handle_return(request, server, *location);
	else
	{
		string resource_path = get_full_resource_path(request, *location);
		if(resource_path[resource_path.length() - 1] == '/')// checks to see if our request doesnt specify a file, supposed to send in an index file
			do_indexing(request, server, location, resource_path);
		else if(location->get_cgi_pass() != "")
			cgi.Cgi_main(request, *this, *location, server);
		else
			get_file_contents(request, server, resource_path);
	}
}

void	Response::handle_post(Request request, Server &server)
{
	Location *location = get_location(request, server);
	if(!location)
		handle_error(request, "403", server);
	else if(check_allowed_methods("POST", *location) == 0) //check allowed methods
		handle_error(request, "405", server);
	else if(location->get_return() != "")
		handle_return(request, server, *location); //check return
	else if(location->get_cgi_pass() == "")
		handle_error(request, "404", server);
	else if(request.get_content_length() != "" && server.get_client_max_body_size() != ""
			&& my_atoi(request.get_content_length()) > my_atoi(server.get_client_max_body_size()))
		handle_error(request, "413", server);
	else if(check_request_body_valid(request) == 0)
		handle_error(request, "422", server);
	else
	{
		Cgi cgi;
		cgi.Cgi_main(request, *this, *location, server);
	}
}

void	Response::handle_delete(Request request, Server &server)
{
	Location *location = get_location(request, server);
	if(!location)
		handle_error(request, "403", server);
	else if(check_allowed_methods("DELETE", *location) == 0)
		handle_error(request, "405", server);
	else if(location->get_return() != "")
		handle_return(request, server, *location);
	//not done yet
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
/////////////////////////////////////////////
/////////////////other utils/////////////////
/////////////////////////////////////////////

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
	if(code == "413")
		return("Payload too large");
	if(code == "422")
		return("Unprocessable Entity");
	if(code == "500")
		return("Internal Server Error");
	return("Unknown Error");
}

string Response::urlDecode(string &str)
{
	string res;

	for(size_t i = 0; i < str.size(); i++)
	{
		if(str[i] == '%' && i < str.size() - 2)
		{
			string temp_hex_str = str.substr(i + 1, 2);
			// Not available on c++98
			// int hex_value = stoi(temp_hex_str, nullptr, 16); //stoi i love u sm idh to manually putnbr base
			int hex_value = my_hex_to_int(temp_hex_str);
			res += static_cast<char>(hex_value);
			i += 2;
		}
		else if(str[i] == '+')
			res += ' ';
		else
			res += str[i];
	}
	return res;
}

Server	&Response::find_server(Request request, vector<Server>& Servers)
{
	for(size_t i = 0; i < Servers.size(); i++)
	{
		if(request.get_port() == Servers[i].get_port())
			return Servers[i];
	}
	throw std::runtime_error("Error: cannot find respective server");
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

string Response::get_full_resource_path(Request request, Location &location)
{
	string encoded_input = request.get_target();
	string decoded_input = urlDecode(encoded_input);
	string res;

	res += "."; // need this if not its gonna be considered absolute path bruh
	if(location.get_root() != "")
		res += location.get_root();
	res += decoded_input;
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
			throw std::runtime_error("Error: invalid return part");
		status_code = return_.substr(pos, temp - pos);
		pos = temp + 1;
	}
	else
		status_code = "302";
	while(return_[pos] == ' ' || return_[pos] == '\t')
		pos++;
	string path = return_.substr(pos, return_.size() - pos);

	this->response_data += get_start_line(request, status_code, server);
	this->response_data += "Location: " + path + "\r\n" + get_headers("", "text/html");
	//surprisingly this one dn code the website can just change the location to the path then it will move u there liao wth
}

int	Response::check_request_body_valid(Request &request)
{
	if(request.get_content_length().length() == 0)
		return 1;
	string req = request.get_data();
	size_t first_boundary_start = req.find("\r\n\r\n") + 4;
	if(first_boundary_start >= req.length())
		return 0;
	size_t boundary_delim = req.find_first_of("\n", first_boundary_start);
	string boundary = req.substr(first_boundary_start, boundary_delim - first_boundary_start);
	size_t find_second_boundary = req.find(boundary);
	if(find_second_boundary == string::npos)
		return 0;
	return 1;
}