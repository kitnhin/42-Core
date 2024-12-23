#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <limits.h>

using std::endl;
using std::cout;
using std::string;
using std::vector;

class Span
{
	private:
	vector<int>		container;
	unsigned int	size;

	public:
	Span();
	Span(const Span &obj);
	~Span();
	Span &operator=(const Span &obj);

	Span(unsigned int N);
	void			addNumber(int n);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();

	class NoSpanException : public std::exception
	{
		const char *what() const throw();
	};
	class LimitReachedException : public std::exception
	{
		const char *what() const throw();
	};
};

#endif