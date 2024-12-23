#include "CheckType.hpp"

bool	isChar(string input)
{
	if(input.length() != 1)
		return false;
	int n = static_cast<int>(input[0]);
	if(n >= 33 && n <= 126) // skip space (32)
		return true;
	return false;
}

int	isPseudoLateral(string input)
{
	if(
		!input.compare("inf") || !input.compare("+inf") || !input.compare("-inf") ||
		!input.compare("nan"))
		return 1;
	if(!input.compare("inff") || !input.compare("+inff") || !input.compare("-inff"))
		return 2;
	return 0;
}