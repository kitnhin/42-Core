#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

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
	Fixed(const int n);
	Fixed& operator=(const Fixed &obj);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif