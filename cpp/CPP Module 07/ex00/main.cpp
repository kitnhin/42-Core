#include "Functions.hpp"

//how nice of them to provide the main for testing

class Awesome
{
	public:
		Awesome(void) : _n(0) {}
		Awesome(int n) : _n(n) {}
		
		Awesome& operator=(Awesome& a) {
			_n = a._n;
			return *this;
		}
		
		bool operator==(Awesome const& rhs) const { return (this->_n == rhs._n); }
		bool operator!=(Awesome const& rhs) const { return (this->_n != rhs._n); }
		bool operator>(Awesome const& rhs) const  { return (this->_n > rhs._n); }
		bool operator<(Awesome const& rhs) const  { return (this->_n < rhs._n); }
		bool operator>=(Awesome const& rhs) const { return (this->_n >= rhs._n); }
		bool operator<=(Awesome const& rhs) const { return (this->_n <= rhs._n); }
		
		int get_n() const { return _n; }

	private:
		int _n;
};

std::ostream& operator<<(std::ostream& o, const Awesome& a) { o << a.get_n(); return o; }

int main( void )
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;


	// Awesome a(2), b(4);
    
    // swap(a, b);
    // std::cout << a << " " << b << std::endl;
    // std::cout << max(a, b) << std::endl;
    // std::cout << min(a, b) << std::endl;
	// return 0;


}



// #include <iostream>
// #include <Array.hpp>

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }