#ifndef HUMANB_H
#define HUMANB_H

#include <iostream>
#include <string>
#include "Weapon.hpp"

using std::string;
using std::cout;
using std::endl;

class HumanB
{
	private:
	string name;
	Weapon *weapon;

	public:
	void	attack();
	HumanB(string name);
	void	setWeapon(Weapon &weapontype);
	~HumanB();
};

#endif