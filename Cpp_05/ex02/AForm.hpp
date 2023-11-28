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

		virtual void beSigned(const Bureaucrat &bur) = 0;
		virtual void execute(Bureaucrat const & executor) const = 0;
		class GradeTooHighException: public std::exception
		{
			std::string _msg;
			public:
				GradeTooHighException(std::string msg = "grade too high") throw();
				~GradeTooHighException() throw();
				const char *what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			std::string _msg;
			public:
				GradeTooLowException(std::string msg = "grade too low") throw();
				~GradeTooLowException() throw();
				const char *what() const throw();
		};

		class AlreadySigned: public std::exception
		{
			public:
				const char *what() const throw();
		};

		class NotSigned: public std::exception
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
