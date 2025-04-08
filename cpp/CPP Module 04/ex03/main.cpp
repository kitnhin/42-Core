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


// int main(void)
// {
//     IMateriaSource *src = new MateriaSource;
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());

//     ICharacter* Yabi = new Character("Yabi");
//     AMateria *tmp;

//     // add Materia to Character (Yabi)
//     {
//         tmp = src->createMateria("ice");
//         Yabi->equip(tmp);
//         tmp = src->createMateria("cure");
//         Yabi->equip(tmp);
//     }
	
// 	Character copy("copy");
// 	Character deep;

// 	tmp = src->createMateria("ice");

// 	copy.equip(tmp);
// 	deep = copy;

// 	deep.use(0, copy);

// 	deep.unequip(0);

// 	copy.use(0, deep);

//     delete Yabi;
//     delete src;

//     return (0);
// }

int main()
{
	ICharacter* me = new Character("me");
	ICharacter* you = new Character("you");

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

	//character tests
	cout << endl << "==== Character ====" << endl << endl;
    AMateria *temp2;
	AMateria *temp3;
	AMateria *temp4;
	AMateria *temp5;
	AMateria *temp6;

	//equip materia
	me->equip(temp); // NULL materia
    temp2 = src->createMateria("ice");
    me->equip(temp2);
    temp3 = src->createMateria("cure");
    me->equip(temp3);
	temp4 = src->createMateria("ice");
	me->equip(temp4);
	temp5 = src->createMateria("cure");
	me->equip(temp5);
	temp6 = src->createMateria("cure");
	me->equip(temp6); //full inventory
	cout << endl;

	//using powers
	me->use(0, *you);
	me->use(1, *you);
	me->use(6, *you); //invalid slot
	cout << endl;

	//invalid unequip idx
	me->unequip(0);
	me->unequip(1);
	me->unequip(1000);
	me->unequip(0);
	cout << endl;

	//test copy assign
	Character lux("lux");
	Character ahri("ahri");
	AMateria *newmat = src->createMateria("ice");
	lux.equip(newmat);
	lux.use(0, ahri);
	ahri = lux;
	ahri.use(0,lux);

	//test deepcopy
	lux.unequip(0);
	lux.use(0, ahri); //lux unequipped dy so cant use
	ahri.use(0, lux); //ahri still can use, showing deep copy

	delete you;
	delete me;
	delete src;
	return 0;
}