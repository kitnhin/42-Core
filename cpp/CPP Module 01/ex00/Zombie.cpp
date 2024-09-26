#include "Zombie.hpp"

using std::string;
using std::cout;
using std::endl;

Zombie::~Zombie()
{
	cout << "Rip " << name << " has died lol" << endl;
}
Zombie::Zombie(string _name)
{
	name = _name;
}

void	Zombie::announce()
{
	cout << name << ": BraiiiiiiinnnzzzZ..." << endl;
}
