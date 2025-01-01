#include "Config.hpp"

Config::Config(string path) : file_path(path), file_data("") 
{
}

void Config::readfile() 
{
    string buffer;
    std::fstream infile(this->file_path);
    if (!infile.is_open())
        throw CustomException("Error: can't open config file");
    else 
    {
        while (std::getline(infile, buffer))
            file_data += buffer + "\n";
        file_data.pop_back();
    }
    cout << file_data << endl;
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
            throw CustomException("Error: server block locating error");
        else 
        {
            pos += 6;
            parse_server_block(pos, server_list);
			skip_whitespaces(pos);
        }
    }
}

void Config::parse_listen_part(size_t &pos, Server &newServer) 
{
    //skip and check trailing spaces
    pos += 6;
    if (this->file_data[pos] != ' ')
        throw CustomException("Error: must have at least one space after 'listen'");
    else
        skip_whitespaces(pos);
    
    //find the end of the listen string and create a substr of the numbers
    size_t host_port_delim = file_data.find_first_of(';', pos);
	if(host_port_delim == file_data.length())
		throw CustomException("Error: listen must at least contain smth");
	string host_port_numbers = file_data.substr(pos, host_port_delim - pos);

	//extract host
	size_t host_delim = file_data.find_first_of(':', pos);
	if(host_delim == pos)
		newServer.set_host("0.0.0.0");
	else
		newServer.set_host(file_data.substr(pos, host_delim - pos));
	
	//extract port
	if(pos == host_port_delim)
		throw CustomException("Error: listen needs a port value as well");
	pos = host_delim + 1;
	newServer.set_port(file_data.substr(pos, host_port_delim - pos));
	pos = host_port_delim + 1;
}

void Config::parse_server_block(size_t &pos, std::vector<Server> &server_list) 
{
    Server newServer;

	skip_whitespaces(pos);
	if (this->file_data[pos] != '{')
		throw CustomException("Error: Server block doesnt have open brackets");
    else
        pos++;
    while (this->file_data[pos] && this->file_data[pos] != '}') 
    {
        skip_whitespaces(pos);
        if (this->file_data.substr(pos, 6) == "listen")
            parse_listen_part(pos, newServer);
    }
	if(this->file_data[pos] != '}')
		throw CustomException("Error: server block need close brackets");

	//skip the closing bracket '}'
	pos++;
	server_list.push_back(newServer);
	cout << "newServer details:" << endl;
	cout << "host: " << newServer.get_host() << endl;
	cout << "port: " << newServer.get_port() << endl;
}