#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	public:
		Form(const std::string &name, int signGrade, int execGrade);
		Form(const Form & src);
		~Form(void);
		Form & operator=(const Form & rhs);

		const std::string &getName() const;
		bool isSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void beSigned(const Bureaucrat &bur);
		class GradeTooHighException: public std::exception
		{
			std::string _msg;
			public:
				GradeTooHighException(std::string msg = "grade is too high") throw();
				~GradeTooHighException() throw();
				const char *what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			std::string _msg;
			public:
				GradeTooLowException(std::string msg = "grade is too low") throw();
				~GradeTooLowException() throw();
				const char *what() const throw();
		};

		class AlreadySigned: public std::exception
		{
			public:
				const char *what() const throw();
		};
	protected:
	private:
		const std::string _name;
		bool _isSigned;
		const int _signGrade;
		const int _execGrade;
};

std::ostream &operator<<(std::ostream &os, const Form &obj);
