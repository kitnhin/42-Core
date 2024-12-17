#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class WrongAnimal
{
protected:
    std::string type;

public:
    string getType() const;
    virtual void makeSound() const; // virtual means can be overwritten by derived class (justyn teach one)

    WrongAnimal();
    WrongAnimal(const WrongAnimal &obj);
    virtual ~WrongAnimal();
    WrongAnimal &operator=(const WrongAnimal &obj);
};

#endif
