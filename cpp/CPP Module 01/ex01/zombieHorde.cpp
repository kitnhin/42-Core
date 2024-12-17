#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *firstzom = new Zombie[N];
	for(int i = 0; i < N; i++)
	{
		firstzom[i].setname(name);
	}
	return firstzom;
}
