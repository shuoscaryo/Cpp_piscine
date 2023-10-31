#include "Brain.hpp"

Brain::Brain(void)
{
}

Brain::Brain(const Brain & src)
{
	*this = src;
}

Brain::~Brain(void)
{
}

Brain & Brain::operator=(const Brain & rhs)
{
	return (*this);
}
