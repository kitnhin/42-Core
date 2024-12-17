#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
	public:
    AMateria    *clone() const;
    void        use(ICharacter &target);

    Cure();
    Cure(const Cure &obj);
    ~Cure();
    Cure &operator=(const Cure &obj);
};

#endif
