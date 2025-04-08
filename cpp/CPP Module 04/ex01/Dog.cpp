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

Dog::Dog(const Dog &obj) : Animal(obj)
{
	cout << "Dog copy constructor called" << endl;
	this->brain = new Brain;
	*brain = *obj.brain;
}

Dog &Dog::operator=(const Dog &obj)
{
	cout << "Dog copy assign operator called" << endl;
	if(this->brain)
		delete this->brain;
	this->brain = new Brain(*obj.brain);
	return (*this);
}

// Dog &Dog::operator=(const Dog &obj)
// {
// 	cout << "Dog SHALLOW copy assign operator called" << endl;
// 	this->type = obj.getType();
// 	brain = obj.brain;
// 	return (*this);
// }


Brain *Dog::getbrain(void)
{
	return brain;
}