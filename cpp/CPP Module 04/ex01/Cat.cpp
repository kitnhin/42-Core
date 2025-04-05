#include "Cat.hpp"

void Cat::makeSound(void) const
{
	cout << "cat noises" << endl;
}

Cat::~Cat()
{
	cout << "cat destroyed" << endl;
	delete brain;
}

Cat::Cat()
{
	cout << "Cat default constructor called" << endl;
	this->type = "Cat";
	brain = new Brain;
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
	cout << "Cat copy constructor called" << endl;
	this->brain = new Brain;
	*brain = *obj.brain;
}

Cat &Cat::operator=(const Cat &obj)
{
	cout << "Cat copy assign operator called" << endl;
	this->type = obj.getType();
	*brain = *obj.brain;
	return (*this);
}

Brain *Cat::getbrain(void)
{
	return brain;
}