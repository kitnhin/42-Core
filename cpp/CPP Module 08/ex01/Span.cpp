#include "Span.hpp"

Span::Span() {}

Span::~Span() {}

Span::Span(const Span &obj)
{
	*this = obj;
}

Span &Span::operator=(const Span &obj)
{
	if(this == &obj)
		return(*this);
	this->size = obj.size;
	this->container = obj.container;
	return(*this);
}

Span::Span(unsigned int N)
{
	this->size = N;
}

const char *Span::NoSpanException::what() const throw()
{
	return("No span can be found");
}

const char *Span::LimitReachedException::what() const throw()
{
	return("Limit reached, no more elements can be stored");
}

void	Span::addNumber(int n)
{
	if(container.size() >= this->size)
		throw LimitReachedException();
	this->container.push_back(n);
}

unsigned int 	Span::longestSpan()
{
	if(container.size() <= 1)
		throw NoSpanException();
	int min_element = *std::min_element(container.begin(), container.end());
	int max_element = *std::max_element(container.begin(), container.end());
	return(max_element - min_element);
}

unsigned int	Span::shortestSpan()
{
	if(container.size() <= 1)
		throw NoSpanException();
	vector<int> temp = container;
	std::sort(temp.begin(), temp.end()); // sort nums first, then compare each 2 nums

	int smallest_diff = INT_MAX;
	for(vector<int>::iterator it = temp.begin(); it < temp.end() - 1; it++)
	{
		int diff = abs(*it - *(it + 1));
		if(diff < smallest_diff)
			smallest_diff = diff;
	}
	return smallest_diff;
}