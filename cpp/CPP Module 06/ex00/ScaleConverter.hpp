#ifndef SCALECONVERTER_HPP
#define SCALECONVERTER_HPP

#include <iostream>
#include "CheckType.hpp"
#include <float.h>
#include <cstdlib>
#include <limits.h>
#include <math.h>

using std::cout;
using std::string;
using std::endl;

class ScaleConverter
{
	private:
	ScaleConverter(); // put inside private so ppl cant instantiate (ai teach one lol for ones its actually useful)

	public:
	ScaleConverter(const ScaleConverter &obj);
	~ScaleConverter();
	ScaleConverter &operator=(const ScaleConverter &obj);

	static void	convert(string input);
};

#endif