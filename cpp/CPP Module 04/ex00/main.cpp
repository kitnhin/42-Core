#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
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

	/////////////////////////////////////////////////////

	cout << "------------ wrong animals: --------------" << endl;

	const WrongAnimal *charlotte = new WrongAnimal();
	const WrongAnimal * charlotte_cat = new WrongCat();
	
	cout << "charlotte type: " << charlotte->getType() << endl;
	cout << "cat type : " << charlotte_cat->getType() << endl;

	charlotte->makeSound();
	charlotte_cat->makeSound();

	delete(charlotte);
	delete(charlotte_cat);

	return 0;
}