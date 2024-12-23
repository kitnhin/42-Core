#include "ScaleConverter.hpp"
#include "CheckType.hpp"

int main(int argc, char **argv)
{
	if(argc != 2)
		cout << "wrong num of arguments" << endl;
	else
		ScaleConverter::convert(argv[1]);
}