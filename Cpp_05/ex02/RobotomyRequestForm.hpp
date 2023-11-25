#pragma once
#include <iostream>

class RobotomyRequestForm
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm & src);
		~RobotomyRequestForm(void);
		RobotomyRequestForm & operator=(const RobotomyRequestForm & rhs);
	protected:
	private:
};

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &obj);
