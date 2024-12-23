#include "ScaleConverter.hpp"

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
	cout << "flaot: " << static_cast<int>(input[0]) << ".0f" <<endl;
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
		input.pop_back(); // popback removes the last f
		cout << "double: " << input << endl; 
	}
}

void	printNums(string input)
{
	try
	{
		double	_double = std::stod(input);
		int		_int = static_cast<int>(_double);
		float	_float = static_cast<float>(_double);
		char	_char = static_cast<char>(_double);

		cout << "char: ";
		if(_int <= 126 && _int >= 33)
			cout << _char << endl;
		else if(_int <= 127 && _int >= 0)
			cout << "non displayable" << endl;
		else
			cout << "impossible" << endl;

		cout << "int: ";
		if(_double <= INT_MAX && _double >= INT_MIN)
			cout << _int << endl;
		else
			cout <<"impossible" << endl;

		cout << "float: ";

		if(_double <= FLT_MAX && _double >= FLT_MIN)
		{
			if(!std::fmod(_double, 1.0)) // fmod compares the decimal places of 1 num to another and returns the diff.
				cout << _float << ".0f" << endl;
			else
				cout << _float << "f" << endl;
		}
		else
			cout << "impossible" << endl;

		cout << "double: ";
		if(!std::fmod(_double, 1.0))
			cout << _double << ".0" << endl;
		else
			cout << _double << endl;
	}
	catch (const std::out_of_range& e)
	{
        std::cerr << "out of range bro wtf u doin" << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "invalid input bruh" << endl;
	}
}

//subject din specify exactly when is conversion impossible, so i just let stod decide when it wanna throw exception for invalid input lol
//cuz stuff like e sometimes r used in nums as well so i v lazy write all the if else so mafan
//stod converts everything before a char (except nums ofc)

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