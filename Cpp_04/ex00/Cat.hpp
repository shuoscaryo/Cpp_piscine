#pragma once
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat & src);
		~Cat(void);
		void makeSound(void) const;
		Cat & operator=(const Cat & rhs);
	protected:
	private:
};
