#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	cout << "Default constructor called" << endl;
	name = "Unnamed";
	hit_points = 10;
	energy_points = 10;
	atk_dmg = 0;
}

ClapTrap::ClapTrap(string name)
{
	cout << "Constructor called" << endl;
	this->name = name;
	hit_points = 10;
	energy_points = 10;
	atk_dmg = 0;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	cout << "Copy constructor called" << endl;
	this->name = obj.name;
	this->hit_points = obj.hit_points;
	this->energy_points = obj.energy_points;
	this->atk_dmg = obj.atk_dmg;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
	cout << "Copy assignment operator called" << endl;
	this->name = obj.name;
	this->hit_points = obj.hit_points;
	this->energy_points = obj.energy_points;
	this->atk_dmg = obj.atk_dmg;
	return *this;
}

ClapTrap::~ClapTrap()
{
	cout << "Destructor called" << endl;
}

void ClapTrap::attack(const std::string& target)
{
	if(energy_points <= 0)
	{
		cout << "ClapTrap " << name << " has no energy" << endl;
		return ;
	}
	else if(hit_points <= 0)
	{
		cout << "ClapTrap " << name << " has already died" << endl;
		return ;
	}
	cout << "ClapTrap " << name << " attacks " << target << ", causing " << atk_dmg << " points of damage!" << endl;
	energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	cout << "ClapTrap " << name << " takes " << amount  << " points of damage!" << endl;
	hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(energy_points <= 0)
	{
		cout << "ClapTrap " << name << " has no energy" << endl;
		return ;
	}
	else if(hit_points <= 0)
	{
		cout << "ClapTrap " << name << " has already died" << endl;
		return ;
	}
	cout << "ClapTrap " << name << " has restored " << amount  << " points of hitpoints!" << endl;
	energy_points--;
}

