#ifndef CUSTOMEXCEPTION_HPP
#define CUSTOMEXCEPTION_HPP

#include "webserv.hpp"

using std::string;

class CustomException : public std::exception
{
	private:
		std::string err_msg;

	public:
	CustomException(string msg);
	const char *what() const throw();
	~CustomException() _NOEXCEPT;
};

#endif