#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	cout << "--------------" << endl;
	cout << "--basic test--" << endl;
	cout << "--------------" << endl;
	DiamondTrap chixia("chixia");
	DiamondTrap yangyang("yangyang");

	cout << "--------------" << endl;
	cout << "---attk test--" << endl;
	cout << "--------------" << endl;
	chixia.attack("yangyang"); //inherited ScavTrap attk

	cout << "------------------" << endl;
	cout << "--functions test--" << endl;
	cout << "------------------" << endl;
	chixia.highFivesGuys();
	chixia.guardGate();
	chixia.whoAmI();
}
//this CPP module is so ass