#include "Dog.hpp"

void Dog::makeSound(void) const
{
	cout << "dog noises" << endl;
}

Dog::~Dog()
{
	cout << "dog destroyed" << endl;
}

Dog::Dog()
{
	cout << "Dog default constructor called" << endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
	cout << "Dog copy constructor called" << endl;
	*this = obj;
}

Dog &Dog::operator=(const Dog &obj)
{
	cout << "Dog copy assign operator called" << endl;
	this->type = obj.getType();
	return (*this);
}
