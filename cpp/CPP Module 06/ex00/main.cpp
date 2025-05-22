#include "ScaleConverter.hpp"
#include "CheckType.hpp"


// int main()
// {
// 	const char *p = "hello";
// 	const int *q = (int*)p; // doesnt warn u and compiles, could lead to undefined behaviour (cuz int 4bytes but char 1byte)
// 	const int *r = static_cast<const int*>(p); //warns u that this is invalid
// 	return 0;
// }


int main(int argc, char **argv)
{
	if(argc != 2)
		cout << "wrong num of arguments" << endl;
	else
		ScaleConverter::convert(argv[1]);
}

//very long havent do command line dy lol so just try it for this


//test cases:

//normal cases:
//42, -42, 0, a, z, 600, 42.4, -42.2, 2147483647, -2147483648, 123abc,
//1e5

//invalid cases:
//string, hello123, 1e999

//notes:
// 1 character inputs are being considered a char
// then anything thats typed gets converted to double first, then type casted to the rest
// i just let stod handle the conversion lmao and see when it wants to throw an error

//implicit cast: int a = 1; float b = a; (dh (int) or static_cast<int>())
//promotion: lower precision to higher (float -> double or int -> float)