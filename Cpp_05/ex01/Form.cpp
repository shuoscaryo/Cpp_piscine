#include "Form.hpp"

Form::Form(const std::string &name, int signGrade, int execGrade):
	_name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (_signGrade < 1)
		throw GradeTooHighException("signGrade too high");
	else if (_execGrade < 1)
		throw GradeTooHighException("execGrade too high");
	else if (_signGrade > 150)
		throw GradeTooLowException("signGrade too low");
	else if (_execGrade > 150)
		throw GradeTooLowException("execGrade too low");

}

Form::Form(const Form & src):
	_name(src._name), _isSigned(src._isSigned),
	_signGrade(src._signGrade), _execGrade(src._execGrade)
{
	//no throws because src is already a correct form
}

Form::~Form(void)
{}

Form & Form::operator=(const Form & rhs)
{
	if (this != &rhs)
	{
		*const_cast<std::string *>(&_name) = rhs._name;
		*const_cast<int *>(&_signGrade) = rhs._signGrade;
		*const_cast<int *>(&_execGrade) = rhs._execGrade;
		_isSigned = rhs._isSigned;
	}
	return (*this);
}

const std::string &Form::getName() const
{
	return (_name);
}

bool Form::isSigned() const
{
	return (_isSigned);
}

int Form::getSignGrade() const
{
	return (_signGrade);
}

int Form::getExecGrade() const
{
	return (_execGrade);
}

void Form::beSigned(const Bureaucrat &bur)
{
	if (bur.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	if (_isSigned)
		throw Form::AlreadySigned();
	_isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const Form &obj)
{
	os << "Form " << obj.getName() << ", sign grade " << obj.getSignGrade()
		<< ", exec grade " << obj.getExecGrade();
	if (obj.isSigned())
		os << ", is signed";
	else
		os << ", is not signed";
	return (os);
}

Form::GradeTooHighException::GradeTooHighException(std::string msg) throw():
	_msg(std::string("Form::GradeTooHighException: ") + msg)
{}

Form::GradeTooHighException::~GradeTooHighException() throw()
{}

const char *Form::GradeTooHighException::what() const throw()
{
	return (_msg.c_str());
}

Form::GradeTooLowException::GradeTooLowException(std::string msg) throw():
	_msg(std::string("Form::GradeTooLowException: ") + msg)
{}

Form::GradeTooLowException::~GradeTooLowException() throw()
{}

const char *Form::GradeTooLowException::what() const throw()
{
	return (_msg.c_str());
}

const char *Form::AlreadySigned::what() const throw()
{
	return ("Form::AlreadySigned: form is already signed");	
}