#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
	AForm(target, 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & src):
	AForm(src)
{}

RobotomyRequestForm::~RobotomyRequestForm(void)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
	}
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout << "Zzzzzzrrrrrrrrrrrrrrr" << std::endl;
	std::string msg[]={" has been robotomized.", " robotomy failed."};
	srand(time(0));
	std::cout << getName() << msg[rand() % 2] << std::endl;
}
