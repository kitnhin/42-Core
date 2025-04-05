#include "Fixed.hpp"

int main( void )
{
	{
		Fixed 		a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		//plus 0.0039 to the actual value cuz we increment the "fixed point value"
		// variable by 1, but later we decrease it by /256 to convert back
		// so technically the actual value only increase by 1/256 = 0.0039...
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;

		std::cout << Fixed::max( a, b ) << std::endl;
	}

	{
		Fixed beru(10);
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "test other stuffs: " << endl;

		cout << "\ntest increments: " << endl;
		cout << "before pre increment: " << beru++ << endl;
		cout << "after pre increment: " << beru << endl;
		beru = 10;
		cout << "post increment: " << ++beru << endl;

		beru = 10;
		cout << "\ntest decrements: " << endl;
		cout << "before pre increment: " << beru-- << endl;
		cout << "after pre increment: " << beru << endl;
		beru = 10;
		cout << "post increment: " << --beru << endl;

		cout << "\ntest min/max: " << endl;
		Fixed iron(11);
		Fixed igris(15);
		Fixed min = Fixed::min(iron, igris);
		Fixed max = Fixed::max(iron, igris);
		cout << "min value: " << min << endl;
		cout << "max value: " << max << endl;

		cout << "\ntest comparison ops (!= , == ....): " << endl;
		cout << "operator:!= result:" << (iron != igris) << "(supposed to return true)" << endl;
		cout << "operator:== result:" << (iron == igris) << "(supposed to return false)" << endl;
		cout << "operator:>= result:" << (iron >= igris) << "(supposed to return false)" << endl;
		cout << "operator:<= result:" << (iron <= igris) << "(supposed to return true)" << endl;
		cout << "operator:>  result:" << (iron > igris) << "(supposed to return false)" << endl;
		cout << "operator:<  result:" << (iron < igris) << "(supposed to return true)" << endl;

		cout << "\ntest math ops: " << endl;
		Fixed yes(12);
		Fixed no(4);
		cout << "operator:+ result:" << yes+no << endl;
		cout << "operator:- result:" << yes-no << endl;
		cout << "operator:* result:" << yes*no << endl;
		cout << "operator:/ result:" << yes/no << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	}
	
	return 0;
}

//will notice that increment 0.0039 instead of 1, because value + 1, but divide 256 so 1/256 = 0.0039