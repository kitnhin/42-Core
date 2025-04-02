#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Weapon
{
	private:

	string type;

	public:

	const string	&getType();
	void	setType(string name);
	Weapon(string name);
	~Weapon();
};

#endif