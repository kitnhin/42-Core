#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

template<typename T>
void	iter(T *arr, int size, void function(T &a))
{
	//unfortunately its rly hard to check for arrsize
	for(int i = 0; i < size; i++)
		function(arr[i]);
}

template<typename T>
void print(T &x) //need to take the const out cuz i will iter only accepts functions that take in without const
{
    std::cout << x << std::endl;
    return;
}

#endif