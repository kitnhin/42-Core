#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "Animal.hpp"
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    void makeSound(void) const;

    WrongCat();
    WrongCat(const WrongCat &obj);
    ~WrongCat();
    WrongCat &operator=(const WrongCat &obj);
};

#endif
