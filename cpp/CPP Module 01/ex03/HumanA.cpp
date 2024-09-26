#include <iostream>
#include <string>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

using std::string;
using std::cout;
using std::endl;

void	HumanA::attack()
{
	cout << name << " attacks with their " << weapon->getType() << endl;
}

HumanA::HumanA(string name, Weapon &weapontype) : weapon(&weapontype)
{
	this->name = name;
}

//need to pass by reference cuz weapon is a pointer, so we need the original var
//lets say we do ...(...Weapon weapontype), we get a copy of weapontype, which is wrong, so the address gonna be wrong also

HumanA::~HumanA()
{
	cout << name << " has been destroyed" << endl;
}

