#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <exception>
#include <deque>

using std::cout;
using std::endl;
using std::string;

class NoOccurrenceFoundException : public std::exception
{
	public:
	const char *what() const throw()
	{
		return("no occurence found unlucky");
	}
};

template<typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator	it = find(container.begin(), container.end(), value);
	if(it == container.end())
		throw NoOccurrenceFoundException();
	return it;
}

#endif