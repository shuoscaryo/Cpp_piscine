#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat & src) : Animal(src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat & Cat::operator=(const Cat & rhs)
{
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}