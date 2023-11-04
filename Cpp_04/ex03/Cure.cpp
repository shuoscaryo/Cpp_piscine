#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(void) : AMateria("cure")
{
}

Cure::Cure(const Cure & src) : AMateria(src)
{
}

Cure::~Cure(void)
{
}

Cure & Cure::operator=(const Cure & rhs)
{
	if (this != &rhs)
		AMateria::operator = (rhs);
	return (*this);
}

AMateria* Cure::clone(void) const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}