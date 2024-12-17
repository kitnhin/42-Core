#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{

	private:
	Brain	*brain;

	public:
	void makeSound(void) const;
	Brain *getbrain(void);

    Cat();
    Cat(const Cat &obj);
    ~Cat();
    Cat &operator=(const Cat &obj);
};

#endif

