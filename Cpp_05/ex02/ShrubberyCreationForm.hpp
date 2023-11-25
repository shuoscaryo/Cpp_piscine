#pragma once
#include <iostream>

class ShrubberyCreationForm
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm & src);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm & rhs);
	protected:
	private:
};

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &obj);
