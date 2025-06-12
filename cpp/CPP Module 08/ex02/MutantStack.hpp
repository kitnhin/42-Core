#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iostream>
#include <exception>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <limits>
#include <list>
#include <limits.h>

using std::endl;
using std::cout;
using std::string;

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
	MutantStack() {}
	MutantStack(const MutantStack &obj) : std::stack<T>(obj)
	{
		*this = obj;
	}
	~MutantStack() {};
	MutantStack &operator=(const MutantStack &obj)
	{
		if(this == &obj)
			return(*this);
		this->c = obj.c;
		return (*this);
	}

	typedef typename std::stack<T>::container_type::iterator iterator; //normally container type is deque
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	iterator begin()
	{
		return (this->c.begin());
	}
	iterator end()
	{
		return (this->c.end());
	}
	const_iterator begin() const
	{
		return this->c.begin();
	}
	const_iterator end() const
	{
		return this->c.end();
	}
};

//stack container is just a container that uses last in first out format (just like a stack)
//however it actually uses another container inside its class:

// template<typename T, typename Container = std::deque<T>>
// class stack
// {
// 	protected:
// 	class Container c;

// 	public:
// 	top(); ...... member functions

// 	using container_type = Container //defining member types
// }

//so wat we need to do it just typedef the iterator from this underlying container (basically using the underlying container iterator as our own)
//very nice website https://en.cppreference.com/w/cpp/container/stack.html

#endif