#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &name):
	AForm(name, 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & src):
	AForm(src)
{}

PresidentialPardonForm::~PresidentialPardonForm(void)
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
	}
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	std::cout << getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
