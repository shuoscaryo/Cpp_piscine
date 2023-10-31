#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(const WrongCat & src);
		~WrongCat(void);
		void makeSound(void) const;
		WrongCat & operator=(const WrongCat & rhs);
	protected:
	private:
};
