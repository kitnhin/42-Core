#include "whatever.hpp"

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
	// int a = 2;
	// int b = 3;
	// ::swap( a, b );
	// std::cout << "a = " << a << ", b = " << b << std::endl;
	// std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	// std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	// std::string c = "chaine1";
	// std::string d = "chaine2";
	// ::swap(c, d);
	// std::cout << "c = " << c << ", d = " << d << std::endl;
	// std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	// std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;


	Awesome a(2), b(4);
    
    swap(a, b);
    std::cout << a << " " << b << std::endl;
    std::cout << max(a, b) << std::endl;
    std::cout << min(a, b) << std::endl;
	//return 0;

	//own test
	int m = 1;
	int n = 2;
	int *ptr1 = &m;
	int *ptr2 = &n;

	std::cout << "address at ptr1: " << ptr1 << std::endl;
	std::cout << "address at ptr2: " << ptr2 << std::endl;
	std::cout << "min ptr: " << min(ptr1, ptr2) << std::endl;
	std::cout << "max ptr: " << max(ptr1, ptr2) << std::endl;
	swap(ptr1, ptr2);
	std::cout << "after swap:" << endl;
	std::cout << "address at ptr1: " << ptr1 << endl;
	std::cout << "address at ptr2: " << ptr2 << endl;

}

//TEST FOR GLOBAL FUNCTION CALLING (::FT)

// namespace test{
//     void yes(){ tsd::cout << "YES from namespace" << std::endl;}
// }
// void    yes()
// {
//     std::cout << "YES" << std::endl;
// }

// int main()
// {
//     int yes = 1;
//     ::yes(); // to call the FUNCTION in GLOBAL SCOPE, so can avoid namespace definitions or variables
//     test::yes();
//     return 0;
// }