#include "Span.hpp"

Span::Span() : size(0)
{
}

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

void	Span::add_multiple_nums(int start, int end, int count)
{
	int curr = 0;
	if(end <= start || count <= 0)
	{
		cout << "invalid args bruh" << endl;
		return ;
	}
	while(curr < count)
	{
		srand(clock()); //need clock instead of time(0) for more randomness cuz time(0) updates slow, resulting in same number
		long n = start + (rand() % (end - start + 1));
		if(n > INT_MAX || n < INT_MIN)
			n = start; // very lazy to handle this bruh since its random generation ig any number is fine as long as no crash
		if(n <= end && n >= start)
		{
			addNumber(static_cast<int>(n)); //exceptions are caught in the main
			curr++;
		}
	}
}

void Span::iterator_add_multiple_nums(vector<int>::iterator start, vector<int>::iterator last)
{
	if(start > last)
	{
		cout << "(iterator) invalid input bruh" << endl;
		return;
	}
	if(std::distance(start, last) + this->container.size() > this->size)
	{
		cout << "throwing size exception cuz cannot add that many nums (nums not added)" << endl;
		throw LimitReachedException();
	}
	this->container.insert(container.end(), start, last);
}

vector<int>	&Span::getContainer()
{
	return this->container;
}

unsigned int Span::getSize()
{
	return this->size;
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