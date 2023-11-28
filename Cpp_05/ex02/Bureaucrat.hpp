#pragma once
#include <iostream>

#define BRC_HIGHEST_RANK 1
#define BRC_LOWEST_RANK 150

class Form;

class Bureaucrat
{
	public:
		Bureaucrat(const std::string &name = "default", int grade = 150);
		Bureaucrat(const Bureaucrat & src);
		~Bureaucrat(void);
		Bureaucrat & operator=(const Bureaucrat & rhs);
		std::string getName() const;
		int	getGrade() const;
		void incrementGrade();
		void decrementGrade();

		void signForm(AForm &form);
		void executeForm(AForm const &form);
		class GradeTooHighException: public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				const char *what() const throw();
		};

	protected:
	private:
		const std::string _name;
		int	_grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bur);