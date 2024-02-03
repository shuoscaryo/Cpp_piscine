#pragma once
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public stack<T> 
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

};
