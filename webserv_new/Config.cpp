#include "Config.hpp"

Config::Config(string path) : file_path(path), file_data("") 
{
}

void Config::readfile() 
{
    string buffer;
    std::fstream infile(this->file_path.c_str());
    if (!infile.is_open())
        throw std::invalid_argument("Error: can't open config file");
    else 
    {
        while (std::getline(infile, buffer))
            file_data += buffer + "\n";
        // file_data.pop_back(); Not available in C++ 98
		file_data.erase(file_data.size()-1);
    }
	infile.close();
    //cout << file_data << endl;
}

void Config::skip_whitespaces(size_t &pos) 
{
    while (this->file_data[pos] && 
           (this->file_data[pos] == ' ' ||
            this->file_data[pos] == '\t' ||
            this->file_data[pos] == '\n'))
        pos++;
}

void Config::main_parse_function(std::vector<Server> &server_list) 
{
    size_t pos = 0;
    readfile();
    while (pos != this->file_data.length()) 
    {
        skip_whitespaces(pos);
        if (this->file_data.substr(pos, 6) != "server")
            throw std::invalid_argument("Error: server block locating error");
        else 
        {
            pos += 6;
            parse_server_block(pos, server_list);
			skip_whitespaces(pos);
        }
    }
	if (server_list.empty())
		throw std::invalid_argument("Error: need a server block inside config file");
}

void Config::parse_listen_part(size_t &pos, Server &newServer) 
{
    //skip and check trailing spaces
    pos += 6;
    if (this->file_data[pos] != ' ')
        throw std::invalid_argument("Error: must have at least one space after 'listen'");
    else
        skip_whitespaces(pos);
    
    //find the end of the listen string and create a substr of the numbers
    size_t host_port_delim = file_data.find_first_of(';', pos);
	if (host_port_delim == file_data.length())
		throw std::invalid_argument("Error: listen must at least contain smth");
	string host_port_numbers = file_data.substr(pos, host_port_delim - pos);

	//extract host
	size_t host_delim = file_data.find_first_of(':', pos);
	if(host_delim == pos)
		newServer.set_host("0.0.0.0");
	else
		newServer.set_host(file_data.substr(pos, host_delim - pos));
	
	//extract port
	if (pos == host_port_delim)
		throw std::invalid_argument("Error: listen needs a port value as well");
	pos = host_delim + 1;
	newServer.set_port(file_data.substr(pos, host_port_delim - pos));

	//set the host-port pair into the socket_addr list
	parse_socket_addr(newServer);

	//adjust pos
	pos = host_port_delim + 1;
}

void Config::parse_server_name_part(size_t &pos, Server &newServer)
{
	//skip and check trailing spaces
    pos += 11;
	if (this->file_data[pos] != ' ')
		throw std::invalid_argument("Error: must have at least one space after 'server_name'");
	else
		skip_whitespaces(pos);

	//idk wat to do wif this lol aiya just substr the part first la
	size_t server_name_delim = file_data.find_first_of(';', pos);
	if(server_name_delim == pos)
		throw std::invalid_argument("Error: server name part must at least contain smth");
	string server_name_part = file_data.substr(pos, server_name_delim - pos);

	//set server name
	newServer.set_server_name(server_name_part);

	//adjust pos
	pos = server_name_delim + 1;
}

void Config::parse_client_body_size(size_t &pos, Server &newServer)
{
	//skip and check trailing spaces
    pos += 20;
    if (this->file_data[pos] != ' ')
        throw std::invalid_argument("Error: must have at least one space after 'server_name'");
    else {
		skip_whitespaces(pos);
	}

	//idk wat to do wif this lol aiya just substr the part first la
	size_t client_body_size_delim = file_data.find_first_of(';', pos);
	if(client_body_size_delim == pos)
		throw std::invalid_argument("Error: client_max_body_size part must at least contain smth");
	string client_body_size_part = file_data.substr(pos, client_body_size_delim - pos);

	//set client body size
	newServer.set_client_max_body_size(client_body_size_part);

	//adjust pos
	pos = client_body_size_delim + 1;
}

void Config::parse_error_pages(size_t &pos, Server &newServer)
{
	//skip "error_pages" in the file data
	pos += 11;

	//check space
    if (this->file_data[pos] != ' ')
        throw std::invalid_argument("Error: must have at least one space after 'error pages'");
    else {
		skip_whitespaces(pos);
	}
	
	//extract the info part
	size_t error_pages_delim = file_data.find_first_of(';', pos);
	if(error_pages_delim == pos)
		throw std::invalid_argument("Error: error_pages part must at least contain smth");
	string error_pages_part = file_data.substr(pos, error_pages_delim - pos);
	size_t slash_pos = error_pages_part.find_first_of('/', 0);
	if(slash_pos == std::string::npos)
		throw std::invalid_argument("Error: cant find / in error pages part");
	
	//extract the parts
	string page_path = error_pages_part.substr(slash_pos, error_pages_part.length() - slash_pos);
	string error_codes = error_pages_part.substr(0, slash_pos);

	//extract each code and assign the value error page address
	size_t space_pos;
	int i = 0;
	while((space_pos = error_pages_part.find_first_of(" ", i)) != std::string::npos)
	{
		string Err_code = error_pages_part.substr(i, space_pos - i);
		newServer.get_error_pages().insert(std::make_pair(Err_code, page_path));
		i = space_pos + 1;
		while(error_pages_part[i] == ' ')
			i++;
	}
	//adjust pos
	pos = error_pages_delim + 1;
}

void Config::parse_socket_addr(Server &newServer)
{
	string host = newServer.get_host();
	string port = newServer.get_port();

	pair<string, string> sock_host_port_pair = std::make_pair(host, port);
	vector<pair<string, string> >::iterator it = std::find(newServer.socket_addr.begin(), newServer.socket_addr.end(), sock_host_port_pair);
	if (it != newServer.socket_addr.end())
		throw std::invalid_argument("Error: duplicate socket host-port address detected");
	newServer.socket_addr.push_back(sock_host_port_pair);
}

void Config::parse_server_block(size_t &pos, std::vector<Server> &server_list) 
{
    Server newServer;

	skip_whitespaces(pos);
	if (this->file_data[pos] != '{')
		throw std::invalid_argument("Error: Server block doesnt have open brackets");
	else
		pos++;
    while (this->file_data[pos] && this->file_data[pos] != '}') 
    {
		skip_whitespaces(pos);
		if (this->file_data.substr(pos, 6) == "listen")
			parse_listen_part(pos, newServer);
		else if (this->file_data.substr(pos, 11) == "server_name")
			parse_server_name_part(pos, newServer);
		else if (this->file_data.substr(pos, 20) == "client_max_body_size")
			parse_client_body_size(pos, newServer);
		else if (this->file_data.substr(pos, 11) == "error_pages")
			parse_error_pages(pos, newServer);
		else if (this->file_data.substr(pos, 8) == "location")
		{
			Location newLocation;
			newLocation.parse_location_main(pos, this->file_data);
			newServer.get_location().push_back(newLocation);
		}
		else if(this->file_data[pos] == '}') //need this incase we encounter '}' after skip_whitespace
			break;
		else
			throw std::invalid_argument("Error: unrecognise directive inside server block");
    }
	if (this->file_data[pos] != '}')
		throw std::invalid_argument("Error: server block need close brackets");
		
	//skip the closing bracket '}'
	pos++;

	//push back the newserver into the list
	server_list.push_back(newServer);
	//print_server(newServer);
}