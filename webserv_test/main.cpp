#include "webserv.hpp"


//damn i wish every file and code can be as short as this
int main(int argc, char **argv)
{
	Config config("testconfig");
	HTTP	http;
	try
	{
		if(argc < 2)
			throw CustomException("Error: wrong number of args");
		http._run_webserv(argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
}