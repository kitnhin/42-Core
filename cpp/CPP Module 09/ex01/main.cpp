#include "RPN.hpp"

int main(int argc, char **argv)
{
	RPN rpn;
	if(argc != 2)
	{
		cerr << "Invalid num of args" << endl;
		return 1;
	}
	try
	{
		rpn.execute_RPN(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	return 0;
}