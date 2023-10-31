#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog & src) : Animal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog & Dog::operator=(const Dog & rhs)
{
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Woof" << std::endl;
}