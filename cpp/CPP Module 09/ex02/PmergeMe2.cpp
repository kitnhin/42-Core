#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	*this = obj;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
	if(this == &obj)
		return(*this);
	this->sorted_vec = obj.sorted_vec;
	this->sorted_deque = obj.sorted_deque;
	return(*this);
}

std::ostream& operator<<(std::ostream& os, const std::pair<int, int>& p)
{
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

const char *PmergeMe::InputErrorException::what() const throw()
{
	return("Invalid input detected");
}