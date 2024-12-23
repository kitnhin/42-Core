#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

template<typename T>
void	iter(T *arr, int size, void function(T &a))
{
	for(int i = 0; i < size; i++)
		function(arr[i]);
}

#endif