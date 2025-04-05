#include "ScavTrap.hpp"

int main()
{

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
	cout << "--test repair--" << endl;
	cout << "---------------" << endl;
	camellya.beRepaired(10);

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