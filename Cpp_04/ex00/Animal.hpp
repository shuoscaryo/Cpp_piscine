#pragma once
#include <iostream>

class Animal
{
	public:
		Animal(void);
		Animal(const Animal & src);
		virtual ~Animal(void);
		virtual void makeSound(void) const;
		Animal & operator=(const Animal & rhs);
	protected:
		std::string type;
};
