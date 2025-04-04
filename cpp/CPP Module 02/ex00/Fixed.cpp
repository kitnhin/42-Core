#include "Fixed.hpp"

Fixed::Fixed()
{
	cout << "Default constructor called" << endl;
	value = 0;
}

Fixed::Fixed(const Fixed &obj)
{
	cout << "Copy constructor called" << endl;
	*this = obj;
}

Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
}

Fixed	&Fixed::operator=(const Fixed &obj)
{
	cout << "Copy assignment operator called" << endl;
	// if(this == &obj)
	// 	return *this; <- this part originally was to block self assignments (obj1 = obj1), but Werror catches that already lol
	value = obj.getRawBits();
	return *this;
}

// need to return (*this) instead of (this) because this is actually a pointer, need to have the same time as the return value (&Fixed)
// the & is neccessary cuz wanna make sure the function returns a REFERENCE of the original instead of a copy

int Fixed::getRawBits(void) const
{
	cout << "getRawBits member function called" << endl;
	return(value);
}

// const outside means this function CANNOT modify any member variables

void Fixed::setRawBits(int const raw)
{
	value = raw;
}

//copy assignment overload is to make sure the copying for new (malloc) memory goes correctly.
// Example

// ====================
// =       Person     =
// =         age      =
// =    skills array  =
// ====================

//       |
// 	     |  copy
// 	     |
// 	     V

// ====================
// =       Person     =
// =         age      =
// =    skills array  =
// ====================

//if skills array is new-ed(malloced) wat happens is the default copy constructor will only copy the ADDRESS stored in the skills array pointer,
//so they will end up pointing to the same array, instead u wanna copy the array so need that (in this question not rly important but ya)

