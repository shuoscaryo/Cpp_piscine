#pragma once
#include <iostream>

class MutantStack
{
	public:
	// Constructors and destructor
		MutantStack(void);
		MutantStack(const MutantStack & src);
		~MutantStack();

	// Setters and getters
		
	// Member functions

	// Operator overloads
		MutantStack & operator=(const MutantStack & rhs);
	protected:
	private:

	friend std::ostream &operator<<(std::ostream &os, const MutantStack &obj);
};

std::ostream &operator<<(std::ostream &os, const MutantStack &obj);
