#pragma once
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(const std::string &name = "default");
		PresidentialPardonForm(const PresidentialPardonForm &src);
		~PresidentialPardonForm(void);
		PresidentialPardonForm & operator=(const AForm &rhs);

		void execute(Bureaucrat const & executor) const;
	protected:
	private:
};
