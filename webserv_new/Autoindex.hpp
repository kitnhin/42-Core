#ifndef AUTOINDEX_HPP
#define AUTOINDEX_HPP

#include "webserv.hpp"

using std::string;

class autoindex
{
	public:
	string	get_file_size(size_t filesize);
	void	generate_autoindex_page_first_part(string &response_body, string dir_name);
	void	generate_autoindex_page_second_part(string &response_body, DIR *dir, string path);

	void	put_file_name(string &response_body, string filename, DIR *checkdir);
	void	put_last_modified_time(string &respons_body, struct stat &file_info);
	void	put_size(string &response_body, struct stat &file_info, DIR *checkdir);
	void	get_file_info(struct stat &file_info, string path_and_name);
};

#endif