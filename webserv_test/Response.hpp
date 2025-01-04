#ifndef RESPONSE_HPP
#define RESPONSE_HPP

#include "Socket.hpp"

using std::string;

class Response
{
	private:
		string response_data;

	public:
		Response();
		~Response();
		void	set_response(string newResponse);
};


#endif