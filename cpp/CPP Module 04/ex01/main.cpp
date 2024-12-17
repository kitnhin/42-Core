#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	//test small stuff
	const Animal *jus = new Animal;
	const Animal *josh = new Dog;
	const Animal *yk = new Cat;

	cout << "animal type: " << jus->getType() << endl;
	cout << "dog type: " << josh->getType() << endl;
	cout << "cat type: " << yk->getType() << endl;

	delete jus;
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

	cout << "------------------------------------" << endl;
	cout << "------------------------------------" << endl;
	Dog dog_copy;
	dog_copy = dog;
	cout << "dog_copy is thinking of: " << dog_copy.getbrain()->getidea(0) << endl;

	return 0;
}