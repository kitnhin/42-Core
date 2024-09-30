#include "ScavTrap.hpp"
#include "FragTrap.hpp"
int main()
{
	cout << "--------------" << endl;
	cout << "--basic test--" << endl;
	cout << "--------------" << endl;
	FragTrap chixia("chixia");
	FragTrap yangyang("yangyang");

	FragTrap encore;
	encore = chixia;

	cout << "--------------" << endl;
	cout << "---attk test--" << endl;
	cout << "--------------" << endl;
	chixia.attack("yangyang");

	cout << "------------------" << endl;
	cout << "--high five test--" << endl;
	cout << "------------------" << endl;
	chixia.highFivesGuys();


}
//this CPP module is so ass