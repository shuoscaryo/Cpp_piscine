#include "AForm.hpp"

AForm::AForm(const std::string &name, int signGrade, int execGrade):
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

AForm::AForm(const AForm & src):
	_name(src._name), _isSigned(src._isSigned),
	_signGrade(src._signGrade), _execGrade(src._execGrade)
{
	//no throws because src is already a correct form
}

AForm::~AForm(void)
{}

AForm & AForm::operator=(const AForm & rhs)
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

const std::string &AForm::getName() const
{
	return (_name);
}

bool AForm::isSigned() const
{
	return (_isSigned);
}

int AForm::getSignGrade() const
{
	return (_signGrade);
}

int AForm::getExecGrade() const
{
	return (_execGrade);
}

void AForm::beSigned(const Bureaucrat &bur)
{
	if (bur.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();
	if (_isSigned)
		throw AForm::AlreadySigned();
	_isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!_isSigned)
		throw AForm::NotSigned();
	if (executor.getGrade() > _execGrade)
		throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const AForm &obj)
{
	os << "Form " << obj.getName() << ", sign grade " << obj.getSignGrade()
		<< ", exec grade " << obj.getExecGrade();
	if (obj.isSigned())
		os << ", is signed";
	else
		os << ", is not signed";
	return (os);
}

//GRADE TOO HIGH
AForm::GradeTooHighException::GradeTooHighException(std::string msg) throw():
	_msg(msg)
{}

AForm::GradeTooHighException::~GradeTooHighException() throw()
{}

const char *AForm::GradeTooHighException::what() const throw()
{
	return (_msg.c_str());
}

//GRADE TOO LOW
AForm::GradeTooLowException::GradeTooLowException(std::string msg) throw():
	_msg(msg)
{}

AForm::GradeTooLowException::~GradeTooLowException() throw()
{}

const char *AForm::GradeTooLowException::what() const throw()
{
	return (_msg.c_str());
}

//ALREADY SIGNED
AForm::AlreadySigned::AlreadySigned(std::string msg) throw():
	_msg(msg)
{}

AForm::AlreadySigned::~AlreadySigned() throw()
{}

const char *AForm::AlreadySigned::what() const throw()
{
	return (_msg.c_str());
}

//NOT SIGNED
AForm::NotSigned::NotSigned(std::string msg) throw():
	_msg(msg)
{}

AForm::NotSigned::~NotSigned() throw()
{}

const char *AForm::NotSigned::what() const throw()
{
	return (_msg.c_str());
}
