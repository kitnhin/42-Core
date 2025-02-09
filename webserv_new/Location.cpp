#include "Location.hpp"

Location::Location() {}

Location::~Location() {}

string Location::get_path()
{
	return this->path;
}

string Location::get_return()
{
	return this->return_;
}

string Location::get_root()
{
	return this->root;
}

vector<string> &Location::get_allowed_methods()
{
	return this->allowed_methods;
}

vector<string>	&Location::get_index()
{
	return this->index;
}

string		Location::get_cgi_pass()
{
	return this->cgi_pass;
}

bool		Location::get_autoindex()
{
	return this->autoindex;
}

void Location::skip_whitespaces(size_t &pos, string file_data) 
{
    while (file_data[pos] && 
           (file_data[pos] == ' ' ||
            file_data[pos] == '\t' ||
            file_data[pos] == '\n'))
        pos++;
}

void	Location::print_location()
{
	cout << "path: " << this->path << endl;
	cout << "allowed_methods:";
	for(vector<string>::iterator it = this->allowed_methods.begin(); it != this->allowed_methods.end(); it++)
		cout << " " << *it;
	cout << endl;
	cout << "roots: " << this->root << endl;
	cout << "index:";
	for(vector<string>::iterator it = this->index.begin(); it != this->index.end(); it++)
		cout << " " << *it;
	cout << endl;
	cout << "cgi_pass: " << this->cgi_pass << endl;
	cout << "return: " << this->return_ << endl;
	cout << "autoindex: " << this->autoindex << endl;
}

void	Location::parse_allowed_methods(size_t &pos, string file_data)
{
	pos += 15;
	
	//check for space after 'allowed_methods'
	if(file_data[pos] != ' ' && file_data[pos] != '\t')
		throw std::runtime_error("Error: need whitespace after 'allowed methods'");
	skip_whitespaces(pos, file_data);

	//find ';'
	size_t temp = file_data.find_first_of(";" , pos);
	if(temp == std::string::npos)
		throw std::runtime_error("Error: can't find ';' in allowed methods");
	
	//extract methods
	size_t temp2 = pos;
	
	while(temp2 != temp)
	{
		temp2 = file_data.find_first_of(" \t;", pos);
		string newMethod = file_data.substr(pos, temp2 - pos);
		if(std::find(this->allowed_methods.begin(), this->allowed_methods.end(), newMethod) == this->allowed_methods.end() &&
			(newMethod == "GET" || newMethod == "POST" || newMethod == "DELETE"))
				this->allowed_methods.push_back(newMethod);
		pos = temp2 + 1;
		skip_whitespaces(pos, file_data);
	}

	//adjust pos
	pos = temp + 1;
}

void	Location::parse_root(size_t &pos, string file_data)
{
	pos += 4;

	//check for space after 'root'
	if(file_data[pos] != ' ' && file_data[pos] != '\t')
		throw std::runtime_error("Error: need whitespace after 'root'");
	skip_whitespaces(pos, file_data);

	//find ';'
	size_t temp = file_data.find_first_of(";" , pos);
	if(temp == std::string::npos)
		throw std::runtime_error("Error: can't find ';' in root");
	string path = file_data.substr(pos, temp - pos);

	//check path and assign root
	if(path[0] != '/')
		throw std::runtime_error("Error root path must begin wif '/'");
	this->root = path;

	//adjust pos;
	pos = temp + 1;
}

void	Location::parse_index(size_t &pos, string file_data)
{
	pos += 5;

	//check for space after 'index'
	if(file_data[pos] != ' ' && file_data[pos] != '\t')
		throw std::runtime_error("Error: need whitespace after 'index'");
	skip_whitespaces(pos, file_data);

	//find ';'
	size_t temp = file_data.find_first_of(";" , pos);
	if(temp == std::string::npos)
		throw std::runtime_error("Error: can't find ';' in index");

	//extract index pages
	size_t temp2 = pos;
	
	while(temp2 != temp)
	{
		temp2 = file_data.find_first_of(" \t;", pos);
		string newFile = file_data.substr(pos, temp2 - pos);
		if(std::find(this->index.begin(), this->index.end(), newFile) == this->index.end())
				this->index.push_back(newFile);
		pos = temp2 + 1;
		skip_whitespaces(pos, file_data);
	}

	//adjust pos
	pos = temp + 1;
}

void	Location::parse_cgi_pass(size_t &pos, string file_data)
{
	pos += 8;

	//check for space after 'cgi_pass'
	if(file_data[pos] != ' ' && file_data[pos] != '\t')
		throw std::runtime_error("Error: need whitespace after 'cgi_pass'");
	skip_whitespaces(pos, file_data);

	//find ';'
	size_t temp = file_data.find_first_of(";" , pos);
	if(temp == std::string::npos)
		throw std::runtime_error("Error: can't find ';' in cgi_pass");
	string path = file_data.substr(pos, temp - pos);

	//check path and assign cgi pass
	if(path[0] != '/')
		throw std::runtime_error("Error root path must begin wif '/'");
	this->cgi_pass = path;

	//adjust pos;
	pos = temp + 1;
}

void	Location::parse_return(size_t &pos, string file_data)
{
	pos += 6;

	//check for space after 'return'
	if(file_data[pos] != ' ' && file_data[pos] != '\t')
		throw std::runtime_error("Error: need whitespace after 'return'");
	skip_whitespaces(pos, file_data);

	//find ';'
	size_t temp = file_data.find_first_of(";" , pos);
	if(temp == std::string::npos)
		throw std::runtime_error("Error: can't find ';' in return");
	string path = file_data.substr(pos, temp - pos);

	this->return_ = path;

	//adjust pos;
	pos = temp + 1;
}

void	Location::parse_autoindex(size_t &pos, string file_data)
{
	pos += 9;

	//check for space after 'autoindex'
	if(file_data[pos] != ' ' && file_data[pos] != '\t')
		throw std::runtime_error("Error: need whitespace after 'autoindex'");
	skip_whitespaces(pos, file_data);

	//find ';'
	size_t temp = file_data.find_first_of(";" , pos);
	if(temp == std::string::npos)
		throw std::runtime_error("Error: can't find ';' in return");
	string status = file_data.substr(pos, temp - pos);

	if(status == "on")
		this->autoindex = true;
	else if(status =="off")
		this->autoindex = false;
	else
		throw std::runtime_error("Error: unknown string after 'autoindex'");

	//adjust pos;
	pos = temp + 1;
}

void	Location::parse_location_main(size_t &pos, string file_data)
{
	//skip "location" in the file data
	pos += 8;

	//skip whitespace
	skip_whitespaces(pos, file_data);

	//check for '/'
	if(file_data[pos] != '/')
		throw std::runtime_error("Error: expected '/' after 'location'");
	
	//get path
	size_t temp = file_data.find_first_of(" \t{", pos);
	this->path = file_data.substr(pos, temp - pos);
	pos = temp;
	skip_whitespaces(pos, file_data);

	//check for '{'
	if(file_data[pos] != '{')
		throw std::runtime_error("Error: can't find open bracket '{' after location");
	pos++;

	//while loop
	while(pos != file_data.length())
	{
		skip_whitespaces(pos, file_data);
		if(file_data.substr(pos, 15) == "allowed_methods")
			parse_allowed_methods(pos, file_data);
		else if(file_data.substr(pos, 4) == "root")
			parse_root(pos, file_data);
		else if(file_data.substr(pos, 5) == "index")
			parse_index(pos, file_data);
		else if(file_data.substr(pos, 8) == "cgi_pass")
			parse_cgi_pass(pos, file_data);
		else if(file_data.substr(pos, 6) == "return")
			parse_return(pos, file_data);
		else if(file_data.substr(pos, 9) == "autoindex")
			parse_autoindex(pos, file_data);
		else if (file_data[pos] == '}')
			break;
		else
			throw std::runtime_error("Error: unknown directerive inside location block");
	}
	
	//check for '}'
	if(file_data[pos] != '}')
		throw std::runtime_error("Error: location block need close bracket '{");
	pos++;
}