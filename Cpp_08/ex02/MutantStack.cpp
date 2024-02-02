#include "MutantStack.hpp"

MutantStack::MutantStack(void)
{
}

MutantStack::MutantStack(const MutantStack & src)
{
	*this = src;
}

MutantStack::~MutantStack()
{
}

MutantStack &MutantStack::operator=(const MutantStack &rhs)
{
	if (this != &rhs)
	{
		// copy
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const MutantStack &obj)
{
	(void)obj;
	return (os);
}
