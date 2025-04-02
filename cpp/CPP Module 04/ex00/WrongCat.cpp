#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat default constructor called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destroyed" << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &obj)
{
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    this->type = obj.getType();
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat noises" << std::endl;
}
