#include "Character.hpp"


Character::Character(string name)
{
	this->name = name;
	for(int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	this->unequipped = NULL;
	unequipped_size = 0;
}

std::string const &Character::getName() const
{
	return this->name;
}

void	Character::print_unequipped()
{
	cout << "unequipped: " << endl;
	for(int i = 0; i < unequipped_size; i++)
		cout << i << ". " << unequipped[i]->gettype() << endl;
	cout << endl;
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
	if (idx >= 0 && idx < 4 && inventory[idx])
	{
		unequipped_handler(inventory[idx]);
		print_unequipped();
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
	this->unequipped = NULL;
	unequipped_size = 0;
}

Character::Character(const Character &obj)
{
	*this = obj;
}

Character::~Character()
{
	if(unequipped)
		delete [] unequipped;
}

Character &Character::operator=(const Character &obj)
{
	this->name = obj.name;
	for(int i = 0; i < 4; i++)
		this->inventory[i] = obj.inventory[i];
	if(obj.unequipped)
	{
		if(this->unequipped)
			delete this->unequipped;
		this->unequipped = new AMateria * [obj.unequipped_size];
		for(int i = 0; i < obj.unequipped_size; i++)
			this->unequipped[i] = obj.unequipped[i];
	}
	return (*this);
}

void Character::unequipped_handler(AMateria *dropped_mat)
{
	if(unequipped_size)
	{
		AMateria **new_unequipped_arr = new AMateria*[unequipped_size + 1];
		for(int i = 0; i < unequipped_size; i++)
			new_unequipped_arr[i] = unequipped[i];
		new_unequipped_arr[unequipped_size] = dropped_mat;
		delete [] unequipped;
		unequipped = new_unequipped_arr;
	}
	else
	{
		unequipped = new AMateria*[1];
		unequipped[0] = dropped_mat;
	}
	unequipped_size++;
}