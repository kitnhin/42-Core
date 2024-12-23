#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

template<typename T>
class Array
{
	private:
	T				*arr;
	unsigned int	size;

	public:
	Array() : size(0)
	{
		this->arr = new T[0];
	}

	Array(const Array &obj)
	{
		*this = obj;
	}

	~Array()
	{
		delete [] this->arr;
	}

	Array &operator=(const Array &obj)
	{
		if(this != &obj)
			delete [] this->arr;
		this->arr = new T[obj.size];
		this->size = obj.size;
		for(unsigned int i = 0; i < this->size; i++)
			this->arr[i] = obj.arr[i];
		return *this;
	}

	Array(unsigned long size)
	{
		this->arr = new T[size];
		this->size = size;
	}

	T &operator[](unsigned int index)
	{
		if(index >= this->size || this->arr == NULL)
			throw FormNotSignedException();
		else
			return(this->arr[index]);
	} //this one helps return the value in the array at which index so u can run Array [i]

	unsigned int getSize()
	{
		return (this->size);
	}

	void	increment_value(unsigned int i) // for testing
	{
		arr[i]++;
	}

	class FormNotSignedException : public std::exception
	{
		public:
			const char *what(void) const throw()
			{
				return ("Index out of bounds not funny");
			}
	};
};

#endif