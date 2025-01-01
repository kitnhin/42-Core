#include "CustomException.hpp"

CustomException::CustomException(string msg) : err_msg(msg) {}

const char *CustomException::what() const throw()
{
	return this->err_msg.c_str(); //stupid la haih always got confused wif char pointer and string
}
CustomException::~CustomException() _NOEXCEPT {}