#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	try
	{
		PmergeMe pm;
		print_and_filter_unsorted_list(argc, argv);
		pm.sort_vec(argc,argv); // prints the after sorted and the time taken
		pm.sort_deque(argc,argv); // prints the time taken
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
}