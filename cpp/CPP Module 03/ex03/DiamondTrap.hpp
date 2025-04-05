#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::endl;

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
	string name;
	public:
    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap &obj);
    DiamondTrap &operator=(const DiamondTrap &obj);
    ~DiamondTrap();

	void		attack(const std::string& target);
	void		whoAmI();
};

#endif