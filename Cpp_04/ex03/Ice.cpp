#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(void) : AMateria("ice")
{
}

Ice::Ice(const Ice & src) : AMateria(src)
{
}

Ice::~Ice(void)
{
}

Ice & Ice::operator=(const Ice & rhs)
{
	if (this != &rhs)
	{
		AMateria::operator = (rhs);
	}
	return (*this);
}

AMateria* Ice::clone(void) const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}