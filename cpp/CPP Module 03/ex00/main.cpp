#include "ClapTrap.hpp"

int main()
{
	ClapTrap rover("rover");
	ClapTrap shorekeeper("shorekeeper");

	cout << "-----------------" << endl;
	cout << "---test attack---" << endl;
	cout << "-----------------" << endl;
	rover.attack("shorekeeper");

	cout << "-----------------" << endl;
	cout << "--test take dmg--" << endl;
	cout << "-----------------" << endl;
	shorekeeper.takeDamage(0);

	cout << "-------------------" << endl;
	cout << "--test restore hp--" << endl;
	cout << "-------------------" << endl;
	shorekeeper.beRepaired(5);

	cout << "---------------" << endl;
	cout << "---test dead---" << endl;
	cout << "---------------" << endl;
	shorekeeper.takeDamage(15);
	shorekeeper.attack("rover");

	cout << "------------------" << endl;
	cout << "--test no energy--" << endl;
	cout << "------------------" << endl;
	for(int i = 0 ; i < 10 ; i++)
		rover.beRepaired(1);

	cout << "--------------------" << endl;
	cout << "--test other stuff--" << endl;
	cout << "--------------------" << endl;
	ClapTrap havocrover;
	havocrover = rover;
	cout << "--------------------" << endl;
}