#include "PmergeMe.hpp"

double gettime()
{
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return static_cast<double>(ts.tv_sec) * 1e6 + static_cast<double>(ts.tv_nsec) / 1e3;
}

int main(int argc, char **argv)
{
	try
	{
		PmergeMe pm;
		// struct timeval start;
		// struct timeval end;

		vector<int> unsorted_arr;
		print_and_filter_unsorted_list(argc, argv);
		//./PmergeMe 11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7
		//./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`

		init_arr(pm.getVec(), argc, argv);
		init_arr(unsorted_arr, argc, argv);
		init_arr(pm.getList(), argc, argv);
	
		double start_vec = gettime();
		merge_insertion_sort(pm.getVec(), 2);
		double end_vec = gettime();
		double time_passed_vec = end_vec - start_vec;

		double start_lst = gettime();
		merge_insertion_sort(pm.getList(), 2);
		double end_lst = gettime();
		double time_passed_lst = end_lst - start_lst;
    	// cout << "unsorted: ";
		// for(size_t i = 0; i < pm.getNums().size(); i++)
        // 	cout << pm.getNums()[i] << " ";
    	// cout << endl;


		cout << "\n\n=============================================================" << endl;

		cout << "Before: ";
		for(size_t i = 0; i < unsorted_arr.size(); i++)
        	cout << unsorted_arr[i] << " ";
		cout << endl;
    	
		cout << "After: ";
    	for(size_t i = 0; i < pm.getVec().size(); i++)
        	cout << pm.getVec()[i] << " ";
    	cout << endl;

		cout << endl;
		cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << time_passed_vec << "µs"<< endl;
		cout << "Time to process a range of " << argc - 1 << " elements with std::list : " << time_passed_lst << "µs"<< endl;

		cout << endl;
		cout << "maximum comparisons: " << maximum_comparisons(pm.getVec().size()) << endl;
		cout << "total comparisions made: " << PmergeMe::num_of_comps / 2 << endl;
		cout << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
}