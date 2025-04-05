#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::endl;

class ScavTrap : public ClapTrap
{
	public:
	ScavTrap();
	ScavTrap(string name);
	ScavTrap(const ScavTrap &obj);
	ScavTrap	&operator=(const ScavTrap &obj);
	void		attack(const std::string& target);
	void		guardGate();
	~ScavTrap();
};

#endif