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

//testcases:

// normal:
// "3 4 +" = 7
// "-1 2 +" = 1
// "1 2 + 3 -"  = 0
// "1 2 * 3 -" = -1
// "4 3 * 2 /" = 6

// eval sheet cases:
// "8 9 * 9 - 9 - 9 - 4 - 1 + " = 42
// "9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -" = 42
// "1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /" = 42

// subject cases:
// "8 9 * 9 - 9 - 9 - 4 - 1 +" = 42
// "7 7 * 7 -" = 42
// "1 2 * 2 / 2 * 2 4 - +" = 0
// "(1 + 1)" = unknown char except

// invalid nums:
// "42 24 +"
// "-10 2 +"

// invaid chars:
// "a 2 +"
// "1 2 + ="

// invalid calculation end:
// "1 2"
// "+ +"
// "2 1 + 3"
// "2 1 + - -"

// divide 0 except:
// "2 0 /"