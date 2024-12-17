#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

// int main()
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());

// 	ICharacter* me = new Character("me");
//     AMateria* tmp;
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("cure");
//     me->equip(tmp);
// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
//  me->use(1, *bob);
// 	delete bob;
//	delete me;
//	delete src;
// 	return 0;
// }

int main()
{
	ICharacter* me = new Character("me");
	//MateriaSource tests
	cout << endl << "==== MateriaSource ====" << endl << endl;
	IMateriaSource* src = new MateriaSource();
	//memory full
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice()); 
	//invalid material creation
	AMateria *temp = src->createMateria("non existing material"); 

	cout << endl << "==== Character ====" << endl << endl;
    AMateria* temp2;
	AMateria *temp3;
	AMateria *temp4;
	AMateria *temp5;
	AMateria *temp6;
	//equip null material
	me->equip(temp);
	//full inventory
    temp2 = src->createMateria("ice");
    me->equip(temp2);
    temp3 = src->createMateria("cure");
    me->equip(temp3);
	temp4 = src->createMateria("ice");
	me->equip(temp4);
	temp5 = src->createMateria("cure");
	me->equip(temp5);
	temp6 = src->createMateria("cure");
	me->equip(temp6);
	//invalid unequip idx
	me->unequip(3);
	me->unequip(3);
	me->unequip(1000);
	//invalid use
	ICharacter* bob = new Character("bob");
	me->unequip(3);
	me->use(3, *bob);
	
	delete bob;
	delete me;
	delete src;
	return 0;
}