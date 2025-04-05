#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	cout << "(ScavTrap) Default constructor called" << endl;
	name = "Unnamed";
	hit_points = 100;
	energy_points = 50;
	atk_dmg = 20;
}

ScavTrap::ScavTrap(string name)
{
	cout << "(ScavTrap) Constructor called" << endl;
	this->name = name;
	hit_points = 100;
	energy_points = 50;
	atk_dmg = 20;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
	cout << "(ScavTrap) Copy constructor called" << endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
{
	cout << "(ScavTrap) Copy assignment operator called" << endl;
	this->name = obj.name;
	this->hit_points = obj.hit_points;
	this->energy_points = obj.energy_points;
	this->atk_dmg = obj.atk_dmg;
	return *this;
}

ScavTrap::~ScavTrap()
{
	cout << "(ScavTrap) Destructor called" << endl;
}

void ScavTrap::attack(const std::string& target)
{
	if(energy_points <= 0)
	{
		cout << "ScavTrap " << name << " has no energy, cant attack" << endl;
		return ;
	}
	else if(hit_points <= 0)
	{
		cout << "ScavTrap " << name << " has already died, cant attack" << endl;
		return ;
	}
	cout << "ScavTrap " << name << " attacks " << target << ", causing " << atk_dmg << " points of damage!" << endl;
	energy_points--;
}

void ScavTrap::guardGate()
{
	if(hit_points <= 0)
	{
		cout << "ScavTrap " << name << " has already died, cant guard" << endl;
		return ;
	}
	cout << "ScavTrap " << name << " has activated guard mode" << endl;
}