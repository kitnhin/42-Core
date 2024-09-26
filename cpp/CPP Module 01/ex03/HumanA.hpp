#ifndef HUMANA_H
#define HUMANA_H

#include <iostream>
#include <string>
#include "Weapon.hpp"

using std::string;
using std::cout;
using std::endl;

class HumanA
{
	private:
	string name;
	Weapon *weapon;

	public:
	void	attack();
	HumanA(string name, Weapon &weapon);
	~HumanA();
};

#endif