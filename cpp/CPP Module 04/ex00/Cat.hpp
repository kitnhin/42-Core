#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
    void makeSound(void) const;

    Cat();
    Cat(const Cat &obj);
    ~Cat();
    Cat &operator=(const Cat &obj);
};

#endif

