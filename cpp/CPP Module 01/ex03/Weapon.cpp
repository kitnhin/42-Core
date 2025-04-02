#include <iostream>
#include <string>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

using std::string;
using std::cout;
using std::endl;

const string &Weapon::getType()
{
	return type;
}

void	Weapon::setType(string name)
{
	this->type = name;
}

Weapon::Weapon(string name)
{
	this->type = name;
}

Weapon::~Weapon()
{
	cout << type << " weapon has been destroyed" << endl;
}

