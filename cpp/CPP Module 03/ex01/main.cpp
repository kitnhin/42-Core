#include "ScavTrap.hpp"

int main()
{
	cout << "=======================================" << endl;
	cout << "============ClapTrap tests=============" << endl;
	cout << "=======================================" << endl;

	cout << "--------------" << endl;
	cout << "--basic test--" << endl;
	cout << "--------------" << endl;
	ClapTrap rover("rover");
	ClapTrap shorekeeper("shorekeeper");
	ClapTrap havocrover;
	havocrover = rover;

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

	cout << "=======================================" << endl;
	cout << "============ScavTrap tests=============" << endl;
	cout << "=======================================" << endl;

	cout << "--------------" << endl;
	cout << "--basic test--" << endl;
	cout << "--------------" << endl;
	ScavTrap jinhsi("Jinhsi");
	ScavTrap camellya("shorekeeper");
	ScavTrap yinlin;
	yinlin = jinhsi;
	cout << "-----------------" << endl;
	cout << "---test attack---" << endl;
	cout << "-----------------" << endl;
	jinhsi.attack("camellya");

	cout << "-----------------" << endl;
	cout << "--test take dmg--" << endl;
	cout << "-----------------" << endl;
	camellya.takeDamage(0); // <- this one still display "ClapTrap", the subject din ask us to recode

	cout << "---------------" << endl;
	cout << "---test guard--" << endl;
	cout << "---------------" << endl;
	camellya.guardGate();
	camellya.guardGate();

	cout << "---------------" << endl;
	cout << "---test dead---" << endl;
	cout << "---------------" << endl;
	camellya.takeDamage(100);
	camellya.attack("jinhsi");
	camellya.guardGate();
	cout << "--------------------" << endl;
}

//noticed that the destructor for the child class is called first (ScavTrap)
//thats because the child class might allocate smth BASED ON the parent / main class
//if u free main class first, u might cause some issues when u wanna free the child class