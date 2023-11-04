#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal & src)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal & rhs)
{
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "<WrongAnimal sound>" << std::endl;
}

const std::string& WrongAnimal::getType(void) const
{
	return (this->type);
}