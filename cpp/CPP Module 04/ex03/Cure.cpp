#include "Cure.hpp"

AMateria *Cure::clone() const
{
    return (new Cure);
}

void Cure::use(ICharacter &target)
{
    cout << "Cure : * heals " << target.getName() << "'s wounds *" << endl;
}

Cure::Cure()
{
    this->type = "cure";
}

Cure::Cure(const Cure &obj) : AMateria(obj)
{
    this->type = "cure";
    *this = obj;
}

Cure &Cure::operator=(const Cure &obj)
{
    this->type = obj.type;
    return (*this);
}

Cure::~Cure()
{
}
