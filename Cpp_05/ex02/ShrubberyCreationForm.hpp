#pragma once
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(const std::string &target = "default");
		ShrubberyCreationForm(const ShrubberyCreationForm & src);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm & operator=(const AForm & rhs);

		void execute(Bureaucrat const & executor) const;
		class FileError : public std::exception
		{
			public:
				const char *what() const throw();
		};
	protected:
	private:
};
