#pragma once
#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal & src);
		~WrongAnimal(void);
		void makeSound(void) const;
		const std::string& getType(void) const;
		WrongAnimal & operator=(const WrongAnimal & rhs);
	protected:
		std::string type;
};
