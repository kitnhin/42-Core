#include "Dog.hpp"

void Dog::makeSound(void) const
{
	cout << "dog noises" << endl;
}

Dog::~Dog()
{
	cout << "dog destroyed" << endl;
	delete brain;
}

Dog::Dog()
{
	cout << "Dog default constructor called" << endl;
	this->type = "Dog";
	brain = new Brain;
}

Dog::Dog(const Dog &obj)
{
	cout << "Dog copy constructor called" << endl;
	*this = obj;
	brain = new Brain;
}

Dog &Dog::operator=(const Dog &obj)
{
	cout << "Dog copy assign operator called" << endl;
	this->type = obj.getType();
	this->brain = new Brain;
	*brain = *obj.brain;
	return (*this);
}

Brain *Dog::getbrain(void)
{
	return brain;
}