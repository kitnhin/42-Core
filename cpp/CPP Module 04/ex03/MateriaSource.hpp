#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
	AMateria *memory [4];

	public:
	MateriaSource();
	MateriaSource(const MateriaSource &obj);
	~MateriaSource();
	MateriaSource &operator=(const MateriaSource &obj);

	void		learnMateria(AMateria* type);
	AMateria*	createMateria(std::string const & type);
};

#endif