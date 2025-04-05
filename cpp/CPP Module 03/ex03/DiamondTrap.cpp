#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    std::cout << "(DiamondTrap) Default constructor called" << std::endl;
    hit_points = 100;
    energy_points = 50;
    atk_dmg = 30;
	name = "unknown";
	ClapTrap::name = name + "_clap_name";
}

DiamondTrap::DiamondTrap(std::string _name)
{
    std::cout << "(DiamondTrap) Constructor called" << std::endl;
    hit_points = 100;
    energy_points = 50;
    atk_dmg = 30;
	this->name = _name;
	ClapTrap::name = this->name + "_clap_name";
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj) : ClapTrap(obj), FragTrap(obj), ScavTrap(obj)
{
    std::cout << "(DiamondTrap) Copy constructor called" << std::endl;
	*this = obj;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj)
{
    std::cout << "(DiamondTrap) Copy assignment operator called" << std::endl;
	this->name = obj.name;
	name = name + "_clap_name";
	FragTrap::hit_points = obj.hit_points;
    ScavTrap::energy_points = obj.energy_points;
    FragTrap::atk_dmg = obj.atk_dmg;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "(DiamondTrap) Destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am " << name << " and my ClapTrap name is " 
              << ClapTrap::name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}