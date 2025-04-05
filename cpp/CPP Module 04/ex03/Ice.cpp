#include "Ice.hpp"

AMateria *Ice::clone() const
{
	return (new Ice);
}


void Ice::use(ICharacter &target)
{
	cout << "Ice : * shoots an ice bolt at " << target.getName() << " *" << endl;
}

Ice::Ice()
{
	this->type = "ice";
}

Ice::Ice(const Ice &obj) : AMateria(obj)
{
	this->type = "ice";
	*this = obj;
}

Ice &Ice::operator=(const Ice &obj)
{
	this->type = obj.type;
	return (*this);
}

Ice::~Ice()
{
}