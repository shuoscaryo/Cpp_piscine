#include "AMateria.hpp"

AMateria::AMateria(void):
	_type("none")
{
}

AMateria::AMateria(std::string const & type):
	_type(type)
{
}

AMateria::AMateria(const AMateria& src)
{
	*this = src;
}

AMateria::~AMateria(void)
{
}

AMateria& AMateria::operator=(const AMateria& src)
{
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

std::string const & AMateria::getType(void) const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}
