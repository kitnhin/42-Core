#include "Fixed.hpp"
#include <climits>

int main( void )
{
	{
		Fixed 		a;
		Fixed const b( 10 );
		Fixed const c( 42.42f );
		Fixed const d( b );

		a = Fixed( 1234.432f );

		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;

		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	}

	{
		cout << "+++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "own tests:" << endl;
		Fixed carlotta(-1);
		Fixed jinhsi(INT_MAX);
		Fixed camellya(-1.1f);

		cout << "+++++++++++++++++++++++++++++++++++++++++++" << endl;
	}
	return 0;

}