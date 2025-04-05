#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

//abstract classes are classes that cant be declared directly (not instantiable)
//for example, if Animal class is abstract, u cant type liddis:
int main()
{
	//this wont work;
	//Animal A; 

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak delete i;
	delete i;

	return 0;
}

//these classes are normally used as base classes / templates for other derived classes