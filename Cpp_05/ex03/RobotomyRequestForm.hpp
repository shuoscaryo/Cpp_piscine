#pragma once
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(const std::string &target = "default");
		RobotomyRequestForm(const RobotomyRequestForm & src);
		~RobotomyRequestForm(void);
		RobotomyRequestForm & operator=(const AForm & rhs);

		void execute(Bureaucrat const &executor) const;
	protected:
	private:
};
