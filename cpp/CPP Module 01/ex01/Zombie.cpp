#include "Zombie.hpp"

Zombie::~Zombie()
{
	cout << "rip zombie has been destroyed" << endl;
}

void	Zombie::announce()
{
	cout << " BraiiiiiiinnnzzzZ..." << endl;
}

void	Zombie::setname(string name)
{
	this->name = name;
}
