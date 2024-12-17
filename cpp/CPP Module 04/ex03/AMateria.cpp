#include "AMateria.hpp"

AMateria::AMateria()
{
	this->type = "unknown material";
}

AMateria::AMateria(const AMateria &obj)
{
	this->type = obj.type;
	*this = obj;
}

AMateria::~AMateria()
{
}

AMateria &AMateria::operator=(const AMateria &obj)
{
	this->type = obj.type;
	return (*this);
}


AMateria::AMateria(string const &type)
{
	this->type = type;
}

string const &AMateria::gettype() const
{
	return (this->type);
}


void	AMateria::use(ICharacter &target)
{
	cout << "Materia " << this->type << "has been used against " << target.getName() << endl;
}