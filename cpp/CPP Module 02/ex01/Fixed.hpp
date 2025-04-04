#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <climits>

using std::cout;
using std::endl;
using std::string;

class Fixed
{
	private:
	int					value;
	static const int	bits = 8;

	public:
	Fixed();
	Fixed(const Fixed &obj);
	Fixed(int num);
	Fixed(float num);
	Fixed& operator=(const Fixed &obj);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	int toInt(void) const;
	float toFloat(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif