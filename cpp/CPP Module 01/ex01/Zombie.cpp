#include "Zombie.hpp"

using std::string;
using std::cout;
using std::endl;

void	Zombie::setname(string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	cout << "Rip " << name << " has died lol" << endl;
}

void	Zombie::announce()
{
	cout << name << ": BraiiiiiiinnnzzzZ..." << endl;
}
