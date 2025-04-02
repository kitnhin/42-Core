#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main()
{
	string str = "HI THIS IS BRAIN";
	string *stringPTR = &str;
	string &stringREF = str;

	cout << "============details==========" << endl;
	cout << "String:" << str << endl;
	cout << "Pointer to string :" << stringPTR << endl;
	cout << "Reference to string : " << stringREF << endl;

	cout << "===========address===========" << endl;
	cout << "Address of string: " << &str << endl;
	cout << "Address of stringPTR: " << &stringPTR << endl;
	cout << "Address of stringREF: " << &stringREF << endl;

	// no we change the value of str
	
	str = "YOUR MOM (pls excuse me im doin this at 3am)";
	cout << "NEW STRING : " << str << endl;

	cout << "============details==========" << endl;
	cout << "String:" << str << endl;
	cout << "Pointer to string :" << stringPTR << endl;
	cout << "Reference to string : " << stringREF << endl;

	cout << "===========address===========" << endl;
	cout << "Address of string: " << &str << endl;
	cout << "Address of stringPTR: " << &stringPTR << endl;
	cout << "Address of stringREF: " << &stringREF << endl;
}

//as we can see, reference is just an alternate name for something
//it has the same address and value
//if u change the value for the str, the value for reference also change accordinly