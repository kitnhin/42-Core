#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
	Brain	*brain;

	public:
    void makeSound(void) const;
	Brain *getbrain(void);

    Dog();
    Dog(const Dog &obj);
    ~Dog();
    Dog &operator=(const Dog &obj);
};

#endif
