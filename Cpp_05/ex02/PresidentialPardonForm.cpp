#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &name):
	AForm(name, 145, 137)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & src)
{
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
	{
		// copy
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &obj)
{
	return (os);
}
