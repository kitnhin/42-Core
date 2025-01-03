#include "webserv.hpp"

int main(int argc, char **argv)
{
	Config config("testconfig");
	HTTP	http;
	(void)argv;
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