#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		cout << "------------ normal animals: --------------" << endl;

		const Animal *meta = new Animal();
		const Animal *j = new Dog();
		const Animal *i = new Cat();

		std::cout << j->getType() << " " << std::endl; 
		std::cout << i->getType() << " " << std::endl; 
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete(meta);
		delete(j);
		delete(i);
	}

	/////////////////////////////////////////////////////

	{
		cout << "\n------------ wrong animals: --------------\n" << endl;

		const WrongAnimal *meta = new WrongAnimal();
		const WrongAnimal *i = new WrongCat();
		const WrongCat *j = new WrongCat();

		cout << endl;
		std::cout << i->getType() << " " << std::endl; 
		std::cout << j->getType() << " " << std::endl; 
		cout << endl;
		i->makeSound(); //will output the WrongAnimal sound!
		j->makeSound(); //will output the WrongCat sound!
		meta->makeSound();
		cout << endl;

		delete(meta);
		delete(j);
		delete(i);
	}

	return 0;
}