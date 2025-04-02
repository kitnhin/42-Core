#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

//abstract classes are classes that cant be declared directly (not instantiable)
//for example, if Animal class is abstract, u cant type liddis:
// int main()
//{
// 		Animal A; <- this wont work
//}

//these classes are normally used as base classes / templates for other derived classes

int main()
{
	//test small stuff
	//const Animal *jus = new Animal; <- uncomment to show that Animal is now abstract
	const Animal *josh = new Dog;
	const Animal *yk = new Cat;
	//Animal A; <- can uncomment this to show it doesnt work

	//cout << "animal type: " << jus->getType() << endl;
	cout << "dog type: " << josh->getType() << endl;
	cout << "cat type: " << yk->getType() << endl;

	//delete jus;
	delete josh;
	delete yk;

	//required by subject
	int n = 10;
	Animal *arr[n]; // an array of pointers
	for(int i = 0; i < (n / 2); i++)
		arr[i] = new Dog;
	for(int i = n/2; i < n; i++)
		arr[i] = new Cat;
	for(int i = 0; i < n; i++)
		delete arr[i];

	//deep copy
	cout << "------------------------------------" << endl;
	cout << "------------------------------------" << endl;
	Dog dog;
	dog.getbrain()->setidea("FURINAAAAAAA", 0);
	cout << "dog is thinking of: " << dog.getbrain()->getidea(0) << endl;

	return 0;
}