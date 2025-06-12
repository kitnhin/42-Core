#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

//templates must be defined in header file worrrrr
//got reason for this one actually haihhhh so long
//when compiling, machine codes for each file is generated
//but if 
//for example: file1 use template wif int data type, the other uses wif string data type
//therefore if u put in somewhere else it might cause linker error


template<typename T>
void	swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T> // wtf have to define template on top of every function
T min(T &a, T &b)
{
	if(a > b)
		return b;
	else
		return a;
}

template<typename T>
T max(T &a, T &b)
{
	if(a < b)
		return b;
	else
		return a;
}

#endif