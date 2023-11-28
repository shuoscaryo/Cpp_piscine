#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void)
{}

Intern::Intern(const Intern & src)
{
	*this = src;
}

Intern::~Intern(void)
{}

Intern &Intern::operator=(const Intern &rhs)
{
	if (this != &rhs)
	{
		// copy
	}
	return (*this);
}

AForm *Intern::makeForm(const std::string &type, const std::string &target)
{
	std::string name[]=
	{
		"robotomy request",
		"shrubbery creation",
		"presidential pardon"
	};
	size_t n_forms = 3;
	for (size_t i = 0; i < n_forms; i++)
	{
		if (name[i] == type)
		{
			switch (i)
			{
				case 0:
					return new RobotomyRequestForm(target);
					break;
				case 1:
					return new ShrubberyCreationForm(target);
					break;
				case 2:
					return new PresidentialPardonForm(target);
					break;
				default:
					std::cout << "Unexpected error" << std::endl;
					return NULL;
			}
		}
	}
	std::cout << "Intern couldn't create form " << type << ": invalid type." << std::endl;
	return (NULL);
}

std::ostream &operator<<(std::ostream &os, const Intern &obj)
{
	(void)obj;
	return (os);
}


