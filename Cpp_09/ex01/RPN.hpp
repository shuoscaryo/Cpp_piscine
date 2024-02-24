#pragma once
#include <iostream>
#include <stack>

class RPN
{
	public:
	// Constructors and destructor
		RPN(void);
		RPN(const RPN & src);
		~RPN();

	// Setters and getters
		
	// Member functions

		static int calculate(const std::string & str);

	// Operator overloads

		RPN & operator=(const RPN & rhs);

	protected:
	private:
	// Atributes

	// Private member functions

};
