#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	cout << "(FragTrap) Default constructor called" << endl;
	name = "Unnamed";
	hit_points = 100;
	energy_points = 100;
	atk_dmg = 30;
}

FragTrap::FragTrap(string name)
{
	cout << "(FragTrap) Constructor called" << endl;
	this->name = name;
	hit_points = 100;
	energy_points = 100;
	//atk_dmg = FragTrap::atk_dmg; <- this doesnt work cuz when ScavTrap is initialised it will overwrite the ClapTrap obj shared between Scav and Frag, rewriting the atkdmg to 20
	atk_dmg = 30;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
	cout << "(FragTrap) Copy constructor called" << endl;	
}

FragTrap &FragTrap::operator=(const FragTrap &obj)
{
	cout << "(FragTrap) Copy assignment operator called" << endl;
	this->name = obj.name;
	this->hit_points = obj.hit_points;
	this->energy_points = obj.energy_points;
	this->atk_dmg = obj.atk_dmg;
	return *this;
}

FragTrap::~FragTrap()
{
	cout << "(FragTrap) Destructor called" << endl;
}

void FragTrap::attack(const std::string& target)
{
	if(energy_points <= 0)
	{
		cout << "FragTrap " << name << " has no energy, cant attack" << endl;
		return ;
	}
	else if(hit_points <= 0)
	{
		cout << "FragTrap " << name << " has already died, cant attack" << endl;
		return ;
	}
	cout << "FragTrap " << name << " attacks " << target << ", causing " << atk_dmg << " points of damage!" << endl;
	energy_points--;
}

void FragTrap::highFivesGuys(void)
{
	cout << name << " is giving a high five!" << endl;
}