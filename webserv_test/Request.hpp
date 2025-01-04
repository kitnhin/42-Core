#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <string>

using std::string;

class Request
{
	private:
		string req_data;

	public:
		Request();
		~Request();
		string	get_data();
		void	set_data(string newdata);
};

#endif