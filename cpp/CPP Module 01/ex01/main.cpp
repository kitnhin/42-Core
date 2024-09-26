#include "Zombie.hpp"

int main()
{
	int n = 1;
	if(n < 1)
	{
		std::cout << "bruh wth" << std::endl;
		return 1;
	}
	Zombie *horde = zombieHorde(n, "zomzom");
	for(int i = 0; i < n; i++)
		horde[i].announce();
	delete [] horde;
	return 0;
}