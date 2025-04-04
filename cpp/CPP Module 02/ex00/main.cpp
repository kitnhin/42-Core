#include "Fixed.hpp"

int main( void )
{
  {
    Fixed a;
    Fixed b(a);
    Fixed c;

    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
  }



  {
    //own tests
    cout << "\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "\ntest default constructor:" << endl;
    Fixed yanbin;
    cout << "\ntest destructor:" << endl;
    {Fixed yanbin2;}
    cout << "\ntest copy constructor:" << endl;
    yanbin.setRawBits(5);
    Fixed yanbin3(yanbin);    

    int n1 = yanbin.getRawBits();
    int n2 = yanbin3.getRawBits();
    cout << "original value at yanbin: " << n1 << endl;
    cout << "original value at yanbin3: " << n2 << endl;
    yanbin3.setRawBits(4);
    n1 = yanbin.getRawBits();
    n2 = yanbin3.getRawBits();
    cout << "new value at yanbin: " << n1 << endl;
    cout << "new value at yanbin3: " << n2 << endl;
  }

  return 0;
}
