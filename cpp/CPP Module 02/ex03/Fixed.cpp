#include "Fixed.hpp"

Fixed::Fixed()
{
	value = 0;
}

Fixed::Fixed(const Fixed &obj)
{
	*this = obj;
}

Fixed::~Fixed()
{
}

Fixed	&Fixed::operator=(const Fixed &obj)
{
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
	if(num < INT_MAX /256 && num >= 0) //have to prevent neg numbers cuz the signed bit would be gone
		this->value = num * 256;
	else
	{
		this->value = 0;
	 	cout << "entered value out of the accepted range" << endl;	
	}	
}


Fixed::Fixed(float num)
{
	if(num < INT_MAX /256 && num >= 0)
		this->value = roundf(num * 256); //rounds floating num to int
	else
	{
		this->value = 0;
		cout << num << endl;
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

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}

//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

bool Fixed::operator < (const Fixed& obj) const
{
	if(this->getRawBits() < obj.getRawBits())
		return true;
	return false;
}

bool Fixed::operator <= (const Fixed& obj) const
{
	if(this->getRawBits() <= obj.getRawBits())
		return true;
	return false;
}

bool Fixed::operator > (const Fixed& obj) const
{
	if(this->getRawBits() > obj.getRawBits())
		return true;
	return false;
}

bool Fixed::operator >= (const Fixed& obj) const
{
	if(this->getRawBits() >= obj.getRawBits())
		return true;
	return false;
}

bool Fixed::operator == (const Fixed& obj) const
{
	if(this->getRawBits() == obj.getRawBits())
		return true;
	return false;
}
bool Fixed::operator != (const Fixed& obj) const
{
	if(this->getRawBits() != obj.getRawBits())
		return true;
	return false;
}

//-------------------------------------------------------------------------

Fixed Fixed::operator + (const Fixed& obj) const
{
	Fixed res;

	res.value = (this->toFloat() + obj.toFloat()) * 256;
	return res;
}

Fixed Fixed::operator - (const Fixed& obj) const
{
	Fixed res;

	res.value = (this->toFloat() - obj.toFloat()) * 256;
	return res;
}

Fixed Fixed::operator * (const Fixed& obj) const
{
	Fixed res;

	res.value = (this->toFloat() * obj.toFloat()) * 256;
	return res;
}

Fixed Fixed::operator / (const Fixed& obj) const
{
	Fixed res;

	res.value = (this->toFloat() / obj.toFloat()) * 256;
	return res;
}

//-------------------------------------------------------------------------

Fixed Fixed::operator ++ (int) //POST
{
	Fixed res(*this); //create another object with the pre incremented value
	this->value++; //increment the original value
	return res; //return the object with the pre incremented value to use
}

//so for POST increment / decrement, u have to create another Fixed obj copy which value has yet to be incremented
//so ur function will use the copied obj, and the value of the original obj will have their value incremented

Fixed &Fixed::operator ++ ()
{
	this->value++;
	return *this;
}

Fixed Fixed::operator -- (int)
{
	Fixed res(*this);
	this->value--;
	return res;
}

Fixed &Fixed::operator -- ()
{
	this->value--;
	return *this;
}

//-------------------------------------------------------------------------

Fixed& Fixed::min(Fixed &obj1, Fixed &obj2)
{
	if(obj1 < obj2)
		return obj1;
	return obj2;
}

const Fixed &Fixed::min(const Fixed &obj1, const Fixed &obj2)
{
	if(obj1 < obj2)
		return obj1;
	return obj2;
}

Fixed& Fixed::max(Fixed &obj1, Fixed &obj2)
{
	if(obj1 > obj2)
		return obj1;
	return obj2;
}

const Fixed& Fixed::max(const Fixed &obj1, const Fixed &obj2)
{
	if(obj1 > obj2)
		return obj1;
	return obj2;
}
