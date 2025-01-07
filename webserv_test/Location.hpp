#ifndef LOCATION_HPP
#define LOCATION_HPP

#include <string>
#include <vector>
#include "webserv.hpp"

using std::string;
using std::vector;

class Location
{
	private:
		string			path; // the route outside the location brackets
		vector<string>	allowed_methods;
		string			root;
		vector<string>	index;
		string			cgi_pass;
		string			return_;
		bool			autoindex; //directory listing

	public:
		Location();
		~Location();

		string get_path();
		void	skip_whitespaces(size_t &pos, string file_data);
		void	print_location();
	
		//get
		vector<string> &get_allowed_methods();
		string		get_return();

		//parse
		void	parse_location_main(size_t &pos, string file_data);
		void	parse_allowed_methods(size_t &pos, string file_data);
		void	parse_root(size_t &pos, string file_data);
		void	parse_index(size_t &pos, string file_data);
		void	parse_cgi_pass(size_t &pos, string file_data);
		void	parse_return(size_t &pos, string file_data);
		void	parse_autoindex(size_t &pos, string file_data);
};

#endif