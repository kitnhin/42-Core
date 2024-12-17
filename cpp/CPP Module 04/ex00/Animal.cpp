#include "Animal.hpp"

string Animal::getType(void) const
{
	return (this->type);
}

void	Animal::makeSound(void) const
{
	cout << "Animal noises" << endl;
}

Animal::Animal()
{
	cout << "Animal default constructor called" << endl;
	this->type = "Unknown animal";
}

Animal::~Animal()
{
	cout << "Animal destroyed" << endl;
}

Animal::Animal(const Animal &obj)
{
	cout << "Animal copy constructor called" << endl;
	*this = obj;
}

Animal &Animal::operator=(const Animal &obj)
{
	cout << "Animal copy operator called" << endl;
	this->type = obj.getType();
	return *this;
}