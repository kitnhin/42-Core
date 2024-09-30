#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::endl;

class ClapTrap
{
	protected: // <- need to change from priv cuz inheritance cant access priv
	string	name;
	int		hit_points;
	int		energy_points;
	int		atk_dmg;

	public:
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	ClapTrap();
	ClapTrap(string name);
	ClapTrap(const ClapTrap &obj);
	ClapTrap &operator=(const ClapTrap &obj);
	~ClapTrap();
};

#endif
