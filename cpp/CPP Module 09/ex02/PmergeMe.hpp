#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <iostream>
#include <fstream>
#include <algorithm>
#include <exception>
#include <vector>
#include <list>
#include <chrono>
#include <deque>
#include <cmath>


using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::list;
using std::pair;
using std::list;
using std::deque;


class PmergeMe
{
	private:
		vector<int> sorted_vec;
		deque<int> sorted_deque;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &obj);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &obj);

		void	sort_deque(int argc, char **argv);
		void	sort_vec(int argc, char **argv);

		class InputErrorException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};
};

//other fts
void	print_and_filter_unsorted_list(int argc, char **argv);
std::ostream& operator<<(std::ostream& os, const std::pair<int, int>& p);

#endif