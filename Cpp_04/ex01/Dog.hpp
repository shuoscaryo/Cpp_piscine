#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(const Dog & src);
		~Dog(void);
		void makeSound(void) const;
		Dog & operator=(const Dog & rhs);
		void addIdea(const std::string &idea);
		void printIdeas(void) const;
	private:
		Brain *brain;
};
