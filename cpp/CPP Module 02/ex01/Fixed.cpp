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
	value = obj.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	return(value);
}

void Fixed::setRawBits(int const raw)
{
	value = raw;
}

Fixed::Fixed(int num)
{
	cout << "Int constructor called" << endl;
	if(num < INT_MAX /256 && num > 0)
		this->value = num * 256;
	else
	{
		this->value = 0;
	 	cout << "entered value out of the accepted range" << endl;	
	}	
}

// so basically, the 8 bits is like the "fractional part" of the number, so since int cannot store decimal, need
// to reserve the last 8 bits to store decimal points (if have)
// example : 
// int num = 5 = 00 00 00 00 00 00 01 01
// num * 256 = 1280 = 00 00 01 01 00000000 <- last 8 bits save up for the fractional
// so when u convert back to print u need divide 256 again to move the bits back
// 256 = 2 ^ 8, cuz 8 fractional bits.

Fixed::Fixed(float num)
{
	cout << "Float constructor called" << endl;
	if(num < INT_MAX /256 && num > 0)
		this->value = roundf(num * 256); //rounds floating num to int
	else
	{
		this->value = 0;
	 	cout << "entered value out of the accepted range" << endl;	
	}	
}

int Fixed::toInt(void) const
{
	int n = value / 256;
	return n;
}

float Fixed::toFloat(void) const
{
	float n = (float)value / 256;
	return n;
}
//example wif float:
//float num = 3.14 = 00000011.00100011
// num * 256 = 803 = 00000011 00100011

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}

//in this case need the overload for the operator << 
//cuz in the main they want << to print the FIXED class
//but << doesnt know how to print that so need to tell it how lol.