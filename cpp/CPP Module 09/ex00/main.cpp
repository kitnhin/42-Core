#include "BitcoinExchange.hpp"


int main(int argc, char **argv)
{
	if(argc != 2)
	{
		cerr << "Error: could not open file" << endl;
		return 1;
	}
	BitcoinExchange yes;
	yes.getData();
	yes.process_input(argv[1]);
	return 0;
}