#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

using std::cout;
using std::endl;
using std::string;

class AMateria
{
	protected:
	string	type;

	public:
	AMateria(const AMateria &obj);
	AMateria();
	virtual ~AMateria();
	AMateria &operator=(const AMateria &obj);

	AMateria(std::string const &type);
	std::string const &gettype() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};


#endif