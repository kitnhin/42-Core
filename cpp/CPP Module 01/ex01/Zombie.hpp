#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Zombie
{
	private:
	string name;

	public:
	void	announce(void);
	void	setname(std::string name);
	~Zombie();
};

Zombie	*zombieHorde(int N, std::string name);

#endif