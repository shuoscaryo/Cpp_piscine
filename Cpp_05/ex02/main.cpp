#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat john("John Johnson", 17);
	Bureaucrat bill("Bill Frontend", 3);
	Bureaucrat django("Django Fett", 26);

	AForm *president = new PresidentialPardonForm("Kali");
	RobotomyRequestForm robots("Manfred");
	ShrubberyCreationForm shrub("Tree!");

	bill.signForm(*president);
	bill.signForm(robots);
	bill.signForm(shrub);

	bill.executeForm(*president);
	bill.executeForm(robots);
	bill.executeForm(shrub);
	return 0;
}