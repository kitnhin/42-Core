#include <iostream>
#include <string>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

using std::string;
using std::cout;
using std::endl;

void	HumanB::attack()
{
	cout << name << " attacks with their " << weapon->getType() << endl;
}

HumanB::HumanB(string name)
{
	this->name = name;
}

void	HumanB::setWeapon(Weapon &weapontype)
{
	weapon = &weapontype;
}

HumanB::~HumanB()
{
	cout << name << " has been destroyed" << endl;
}