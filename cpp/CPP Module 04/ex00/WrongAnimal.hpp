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
    void makeSound() const;

    WrongAnimal();
    WrongAnimal(const WrongAnimal &obj);
    virtual ~WrongAnimal();
    WrongAnimal &operator=(const WrongAnimal &obj);
};

#endif
