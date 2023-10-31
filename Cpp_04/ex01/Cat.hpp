#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat & src);
		~Cat(void);
		void makeSound(void) const;
		Cat & operator=(const Cat & rhs);
		void addIdea(const std::string &idea);
		void printIdeas(void) const;
	protected:
	private:
		Brain *brain;
};
