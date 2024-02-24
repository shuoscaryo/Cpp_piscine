#pragma once
#include <iostream>

class PmergeMe
{
	public:
	// Constructors and destructor
		PmergeMe(void);
		PmergeMe(const PmergeMe & src);
		~PmergeMe();

	// Setters and getters
		
	// Member functions

	// Operator overloads
		PmergeMe & operator=(const PmergeMe & rhs);

	protected:
	private:
	// Atributes

	// Private member functions

	// Friends <3
		friend std::ostream &operator<<(std::ostream &os, const PmergeMe &obj);
};

std::ostream &operator<<(std::ostream &os, const PmergeMe &obj);
