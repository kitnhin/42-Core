#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::endl;

class FragTrap : public ClapTrap
{
	public:
	FragTrap();
	FragTrap(string name);
	FragTrap(const FragTrap &obj);
	FragTrap	&operator=(const FragTrap &obj);
	void		attack(const std::string& target);
	void		highFivesGuys(void);
	~FragTrap();
};

#endif