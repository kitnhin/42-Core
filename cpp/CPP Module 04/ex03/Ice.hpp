#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
	public:
	AMateria	*clone() const;
	void		use(ICharacter &target);
	
	Ice();
	Ice(const Ice &obj);
	~Ice();
	Ice &operator=(const Ice &obj);
};

#endif