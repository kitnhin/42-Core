#include "Cat.hpp"

void Cat::makeSound(void) const
{
	cout << "cat noises" << endl;
}

Cat::~Cat()
{
	cout << "cat destroyed" << endl;
}

Cat::Cat()
{
	cout << "Cat default constructor called" << endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
	cout << "Cat copy constructor called" << endl;
	*this = obj;
}

Cat &Cat::operator=(const Cat &obj)
{
	cout << "Cat copy assign operator called" << endl;
	this->type = obj.getType();
	return (*this);
}