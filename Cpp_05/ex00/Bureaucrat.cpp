#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade > BRC_LOWEST_RANK)
		throw Bureaucrat::GradeTooLowException();
	if (grade < BRC_HIGHEST_RANK)
		throw Bureaucrat::GradeTooHighException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat & src)
{
	*this = src;
}

Bureaucrat::~Bureaucrat(void)
{}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & rhs)
{
	if (this != &rhs)
	{
		_grade = rhs._grade;
		*const_cast<std::string *>(&_name) = rhs._name;
	}
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::incrementGrade()
{
	if (_grade <= BRC_HIGHEST_RANK)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= BRC_LOWEST_RANK)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}


std::ostream &operator<<(std::ostream &os, const Bureaucrat &bur)
{
	os << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".";
	return os;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat::GradeTooHighException: Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat::GradeTooLowException: Grade is too low!");
}