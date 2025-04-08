#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Animal
{
	protected:
	std::string type;

	public:
	string getType(void) const;
	virtual void makeSound(void) const = 0; // pure virtual class cuz of -0, so cant be instantiated
	Animal();
	Animal(const Animal &obj);
	virtual ~Animal();
	Animal &operator=(const Animal &obj);
};

#endif