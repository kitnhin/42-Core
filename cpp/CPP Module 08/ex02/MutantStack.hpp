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

using std::endl;
using std::cout;
using std::string;

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
	MutantStack() {}
	MutantStack(const MutantStack &obj)
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

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin()
	{
		return (this->c.begin());
	}
	iterator end()
	{
		return (this->c.end());
	}
};

//stack container is just a container that uses last in first out format (just like a stack)
//however it also uses a normal container (probably list or vector) to store its values, it just works like a stack (basically a container acting like a stack)
//so wat we need to do it just typedef the iterator from this underlying container (basically using the underlying container iterator as our own)
//then we implement the functions this new "iterator" used in the main provided by using the original iterator (from the underlying container) lol

//honestly feels abit weird but aiya it works it works la

#endif