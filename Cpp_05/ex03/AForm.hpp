#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
	public:
		AForm(const std::string &name, int signGrade, int execGrade);
		AForm(const AForm & src);
		virtual ~AForm(void);
		virtual AForm & operator=(const AForm & rhs) = 0;

		const std::string &getName() const;
		bool isSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void beSigned(const Bureaucrat &bur);
		virtual void execute(Bureaucrat const & executor) const = 0;
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
			std::string _msg;
			public:
				AlreadySigned(std::string msg = "form is already signed") throw();
				~AlreadySigned() throw();
				const char *what() const throw();
		};

		class NotSigned: public std::exception
		{
			std::string _msg;
			public:
				NotSigned(std::string msg = "form is not signed") throw();
				~NotSigned() throw();
				const char *what() const throw();
		};

	protected:
	private:
		const std::string _name;
		bool _isSigned;
		const int _signGrade;
		const int _execGrade;
};

std::ostream &operator<<(std::ostream &os, const AForm &obj);