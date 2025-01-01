#include "HTTP.hpp"

HTTP::HTTP() {}

HTTP::~HTTP() {}

std::vector<Server> &HTTP::get_servers()
{
	return(this->Servers);
}