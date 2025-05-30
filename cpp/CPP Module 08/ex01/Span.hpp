#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>

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
	void			add_multiple_nums(int start, int end, int count);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();
	void			iterator_add_multiple_nums(vector<int>::iterator start, vector<int>::iterator last);

	unsigned int	getSize();
	vector<int>		&getContainer();

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