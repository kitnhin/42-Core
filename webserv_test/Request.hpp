#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <map>
#include <vector>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>

//somehow cant include even a single hpp file here if not will have error 

using std::string;
using std::cout;
using std::endl;

class Request
{
	private:
		string req_data;
		//parts of the request
		string method;
		string target;
		string http_ver;
		string host;
		string port;
		string content_length;
		std::map<string, string> header_fields;
		string body;

	public:
		Request();
		~Request();
		string	get_data();
		void	set_data(string newdata);

		//get
		string	get_req_data();
		string	get_method();
		string	get_target();
		string	get_http_ver();
		string	get_host();
		string	get_port();
		string	get_content_length();
		std::map<string, string> get_header_fields();
		string	get_body();


		//parsing
		void	parse_request_data_main();
		void	parse_request_line(size_t &pos);
		void	parse_header_fields(size_t &pos);
		void	parse_body(size_t &pos);
		void	parse_host_port(string str);
};

void	print_request(Request request);


#endif