#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	public:
    void makeSound(void) const;

    Dog();
    Dog(const Dog &obj);
    ~Dog();
    Dog &operator=(const Dog &obj);
};

#endif
