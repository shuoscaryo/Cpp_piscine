#pragma once
#include <iostream>
#include "AForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern & src);
		~Intern();
		Intern & operator=(const Intern & rhs);

		AForm *makeForm(const std::string &type, const std::string &target);
	protected:
	private:
};

std::ostream &operator<<(std::ostream &os, const Intern &obj);
