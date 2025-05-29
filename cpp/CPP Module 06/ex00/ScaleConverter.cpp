#include "ScaleConverter.hpp"
#include <cmath>

//aiya i hate doing this la so mafan

ScaleConverter::ScaleConverter()
{
}

ScaleConverter::ScaleConverter(const ScaleConverter &obj)
{
	*this = obj;
}

ScaleConverter::~ScaleConverter()
{
}

ScaleConverter &ScaleConverter::operator=(const ScaleConverter &obj)
{
	if(this == &obj)
		return (*this);
	(void)obj;
	return (*this);
}

//actual functions
void	printChar(string input)
{
	cout << "char: " << input << endl;
	cout << "int: " << static_cast<int>(input[0]) << endl;
	cout << "float: " << static_cast<int>(input[0]) << ".0f" <<endl;
	cout << "double: " << static_cast<int>(input[0]) << ".0" << endl;
}

void	printPseudoLateral(string input, int n)
{
	cout << "char: impossible" << endl;
	cout << "int: impossible" << endl;
	if(n == 1)
	{
		cout << "float: " << input << "f" << endl;
		cout << "double: " << input << endl;
	}
	else if(n == 2)
	{
		cout << "float: " << input << endl;
		input.erase(input.size() - 1); // popback removes the last f
		cout << "double: " << input << endl; 
	}
}

void	printNums(string input)
{
	try
	{
		double	_double = std::strtod(input.c_str(), 0);
		if(_double == 0 && input != "0")
			_double = INFINITY;
		int		_int = static_cast<int>(_double);
		float	_float = static_cast<float>(_double);
		char	_char = static_cast<char>(_double);

		cout << "char: ";
		if(_int <= 126 && _int >= 33) // displayable ascii chars
			cout << _char << endl;
		else if(_int <= 127 && _int >= 0) // valid ascii range
			cout << "Non displayable" << endl;
		else
			cout << "impossible" << endl;

		cout << "int: ";
		if(_double <= INT_MAX && _double >= INT_MIN)
			cout << _int << endl;
		else
			cout <<"impossible" << endl;

		cout << "float: ";
		if(_double <= FLT_MAX && _double >= -FLT_MAX) //NOT float min cuz that gives the smallest positive number
		{
			if(!std::fmod(_double, 1.0)) // fmod compares the decimal places of 1 num to another and returns the diff.
				cout << _float << ".0f" << endl;
			else
				cout << _float << "f" << endl;
		}
		else
			cout << "impossible" << endl;

		cout << "double: ";
		if(_double == INFINITY)
			cout << "impossible" << endl;
		else if(!std::fmod(_double, 1.0))
			cout << _double << ".0" << endl;
		else
			cout << _double << endl;
	}
	catch (const std::out_of_range& e)
	{
        std::cerr << "out of range bro wth u doin" << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "invalid input bruh" << endl;
	}
}

void	ScaleConverter::convert(string input)
{
	int n;
	if(isChar(input) == true)
		printChar(input);
	else if ((n = isPseudoLateral(input)) != 0)
		printPseudoLateral(input, n);
	else
		printNums(input);
}