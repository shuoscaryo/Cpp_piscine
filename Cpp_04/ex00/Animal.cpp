#include "Animal.hpp"

Animal::Animal(void) : type("Animal")
{
	std::cout<<"Animal default constructor called"<<std::endl;
}

Animal::Animal(const Animal & src)
{
	std::cout<<"Animal copy constructor called"<<std::endl;
	*this = src;
}

Animal::~Animal(void)
{
	std::cout<<"Animal destructor called"<<std::endl;
}

Animal & Animal::operator=(const Animal & rhs)
{
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

void Animal::makeSound(void) const
{
	std::cout<<"<Animal sound>"<<std::endl;
}

const std::string& Animal::getType(void) const
{
	return (this->type);
}