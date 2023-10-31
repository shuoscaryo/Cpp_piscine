#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat & src) : WrongAnimal(src)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = src;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat & WrongCat::operator=(const WrongCat & rhs)
{
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}