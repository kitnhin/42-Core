#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	cout << "(ClapTrap) Default constructor called" << endl;
	name = "Unnamed";
	hit_points = 10;
	energy_points = 10;
	atk_dmg = 0;
}

ClapTrap::ClapTrap(string name)
{
	cout << "(ClapTrap) Constructor called" << endl;
	this->name = name;
	hit_points = 10;
	energy_points = 10;
	atk_dmg = 0;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	cout << "(ClapTrap) Copy constructor called" << endl;
	this->name = obj.name;
	this->hit_points = obj.hit_points;
	this->energy_points = obj.energy_points;
	this->atk_dmg = obj.atk_dmg;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
	cout << "(ClapTrap) Copy assignment operator called" << endl;
	this->name = obj.name;
	this->hit_points = obj.hit_points;
	this->energy_points = obj.energy_points;
	this->atk_dmg = obj.atk_dmg;
	return *this;
}

ClapTrap::~ClapTrap()
{
	cout << "(ClapTrap) Destructor called" << endl;
}

void ClapTrap::attack(const std::string& target)
{
	if(energy_points <= 0)
	{
		cout << "ClapTrap " << name << " has no energy, cant attack" << endl;
		return ;
	}
	else if(hit_points <= 0)
	{
		cout << "ClapTrap " << name << " has already died, cant attack" << endl;
		return ;
	}
	cout << "ClapTrap " << name << " attacks " << target << ", causing " << atk_dmg << " points of damage!" << endl;
	energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(hit_points <= 0)
	{
		cout << "ClapTrap " << name << " has already died, therefore cant take dmg lol" << endl;
		return ;
	}
	cout << "ClapTrap " << name << " takes " << amount  << " points of damage!" << endl;
	hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(energy_points <= 0)
	{
		cout << "ClapTrap " << name << " has no energy, cant repair" << endl;
		return ;
	}
	else if(hit_points <= 0)
	{
		cout << "ClapTrap " << name << " has already died, cant repair" << endl;
		return ;
	}
	cout << "ClapTrap " << name << " has restored " << amount  << " points of hitpoints!" << endl;
	energy_points--;
}

