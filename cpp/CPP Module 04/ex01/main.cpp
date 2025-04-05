#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak delete i;
	delete i;

	//test small stuff
	cout << "\n=======test small stuff=======\n" << endl;
 	const Animal *jus = new Animal;
	const Animal *josh = new Dog;
	const Animal *yk = new Cat;

	cout << "animal type: " << jus->getType() << endl;
	cout << "dog type: " << josh->getType() << endl;
	cout << "cat type: " << yk->getType() << endl;

	delete jus;
	delete josh;
	delete yk;

	//test arr
	cout << "\n=======test array=======\n" << endl;

	//required by subject
	int n = 4;
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
	cout << "dog_copy is currently thinking of: " << dog_copy.getbrain()->getidea(0) << endl;
	dog_copy.getbrain()->setidea("CARLOTTAAAA", 0);
	cout << "dog_copy is now thinking of: " << dog_copy.getbrain()->getidea(0) << endl;
	cout << "original dog is thinking of: " << dog.getbrain()->getidea(0) << endl;

	cout << "\n====== eval sheet test=========\n" << endl;
	Dog basic;
	{
		cout << "\ntmp stuff\n" << endl;
		Dog tmp = basic;
		cout << "\nend of temp stuff\n" << endl;
	}
	cout << "---------------------" << endl;
	basic.getbrain()->setidea("COOKIE AND CREAM", 0);
	cout << "basic dog is thinking of: " << basic.getbrain()->getidea(0) << endl;
	//as we can see, the basic dog can still use its brain, meaning deep copy cuz the brain deleted in tmp is diff from basic
	return 0;
}

//destructor needs to be virtual cuz lets say we have example below:

// int main()
// {
// 	Animal *dog = new dog();
// 	delete dog;
// }

//the destructor called will be the Animal destructor, not the dog destructor
//so since the dog might have extra stuff that might be diff from animal (cuz inheritence), calling dog destructor is more acc

//Polymorphism assigning or referencing a derived class through a base class pointer/reference like Animal *dog = new dog()