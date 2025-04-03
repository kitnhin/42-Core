#include "Zombie.hpp"

int main()
{
	int n = 5;
	if(n < 1)
	{
		std::cout << "bruh wth" << std::endl;
		return 1;
	}
	Zombie *horde = zombieHorde(n, "zomzom");
	for(int i = 0; i < n; i++)
		horde[i].announce();
	cout << "++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "firstzom tests:\n\n";
	cout << "firstzom addr: " << &horde[0] << endl;
	cout << "horde first ptr addr: " << horde << endl;
	if(horde == &horde[0])
		cout << "shown that horde is pointing to first zom" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++" << endl;
	delete [] horde;
	return 0;
}