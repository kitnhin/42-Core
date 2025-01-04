#include "Request.hpp"

Request::Request() {}

Request::~Request() {}

string Request::get_data()
{
	return this->req_data;
}

void Request::set_data(string newdata)
{
	this->req_data = newdata;
}