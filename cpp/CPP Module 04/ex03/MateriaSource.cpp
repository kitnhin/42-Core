#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for(int i = 0; i < 4; i++)
		memory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
	*this = obj;
}

MateriaSource::~MateriaSource()
{
	for(int i = 0; i < 4; i++)
		if(memory[i])
			delete memory[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &obj)
{
	for(int i = 0; i < 4; i++)
		this->memory[i] = obj.memory[i];
	return (*this);
}

void		MateriaSource::learnMateria(AMateria* type)
{
	int i = 0;
	while(i < 4 && memory[i])
		i++;
	if(i < 4)
		memory[i] = type;
	else
	{
		cout << "no slots left to learn Materia" << endl;
		if (type != NULL)
			delete type;
	}
}

AMateria*	MateriaSource::createMateria(std::string const &type)
{
	for(int i = 0; i < 4; i++)
		if(memory[i] && type == memory[i]->gettype())
			return memory[i];
	cout << "Materia not learned" << endl;
	return NULL;
}