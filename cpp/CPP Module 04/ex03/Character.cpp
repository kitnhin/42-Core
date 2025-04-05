#include "Character.hpp"

Character::Character(string name)
{
	this->name = name;
	for(int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	for(int i = 0; i < 100; i++)
		this->unequipped[i] = NULL;
}

std::string const &Character::getName() const
{
	return this->name;
}

void	Character::equip(AMateria* m)
{
	if(!m)
		cout << "NULL material lol" << endl;
	int i = 0;
	while(i < 4 && this->inventory[i])
		i++;
	if (i < 4)
		inventory[i] = m;
	else
		cout << "inventory full" << endl;
}

void	Character::unequip(int idx)
{
	if (inventory[idx])
	{
		int i = 0;
		while(unequipped[i] && i < 100)
			i++;
		unequipped[i] = inventory[idx];
		inventory[idx] = NULL;
	}
	else
		cout << "nth to unequip at this slot" << endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx <= 3 && idx >= 0 && this->inventory[idx])
		inventory[idx]->use(target);
	else
		cout << "nth to use at that slot" << endl;
}

Character::Character()
{
	this->name = "unnamed";
	for(int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	for(int i = 0; i < 100; i++)
		this->unequipped[i] = NULL;
}

Character::Character(const Character &obj)
{
	for(int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	for(int i = 0; i < 100; i++)
		this->unequipped[i] = NULL;
	*this = obj;
}

Character::~Character()
{
	// for(int i = 0; i < 4; i++)
	// 	if(inventory[i])
	// 		delete inventory[i];
	// for(int i = 0; i < 100; i++)
	// 	if(unequipped[i])
	// 		delete unequipped[i];

	//^^^ dunno why dont need to free wth
}

Character &Character::operator=(const Character &obj)
{
	this->name = obj.name;
	for(int i = 0; i < 4; i++)
		this->inventory[i] = obj.inventory[i];
	for(int i = 0; i < 100; i++)
		this->unequipped[i] = obj.inventory[i];
	return (*this);
}