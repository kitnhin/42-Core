#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main()
{
	string str =  "HI THIS IS BRAIN";
	string *stringPTR =  &str;
	string &stringREF = str; 
	//ref is an alias (alternate name) of the original var, basically allow u to modify the original value, like dereferancing in c (*x)++;

	cout << "String: " << str << endl;
	cout << "Pointer to string: " << stringPTR << endl;
	cout << "Reference to string: " << stringREF << endl;
	cout << "Address of string: " << &str << endl;
	cout << "Address of pointer: " << &stringPTR << endl;
	cout << "Address of reference: " << &stringREF << endl;

	//ref and original have the same address
	
	cout << "==================================================" << endl;

	stringREF = "HI THIS IS NOT NOT BRAIN"; //change the ref

	cout << "String: " << str << endl;
	cout << "Pointer to string: " << stringPTR << endl;
	cout << "Reference to string: " << stringREF << endl;

	// as shown, the original str also change

	cout << "Address of string: " << &str << endl;
	cout << "Address of pointer: " << &stringPTR << endl;
	cout << "Address of reference: " << &stringREF << endl;

	// address remain the same
	return 0;
}