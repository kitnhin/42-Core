#include "Zombie.hpp"

Zombie::~Zombie()
{
	cout << "rip: " << name << " has been destroyed" << endl;
}

void	Zombie::announce()
{
	cout << name << ": BraiiiiiiinnnzzzZ..." << endl;
}

void	Zombie::setname(string name)
{
	this->name = name;
}
