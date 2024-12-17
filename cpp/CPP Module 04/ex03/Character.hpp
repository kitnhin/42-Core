#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character: public ICharacter
{
	private:
	string		name;
	AMateria	*inventory[4];
	AMateria	*unequipped [100];

	public:
	Character(string name);
	std::string const &getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

	~Character();
	Character();
	Character(const Character &obj);
	Character &operator=(const Character &obj);
};

#endif