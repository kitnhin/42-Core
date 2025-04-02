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
	if(weapon)
		cout << name << " attacks with their " << weapon->getType() << endl;
	else
		cout << name << " has no weapon cant attk" << endl;
}

HumanB::HumanB(string name)
{
	this->name = name;
	this->weapon = NULL;
}

void	HumanB::setWeapon(Weapon &weapontype)
{
	weapon = &weapontype;
}

HumanB::~HumanB()
{
	cout << name << " has been destroyed" << endl;
}