#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

#define PURPLE "\033[1;35m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

int main()
{
	{
		std::cout << PURPLE "TEST: Everything works fine" RESET << std::endl;
		Bureaucrat bill("Bill Frontend", 3);

		std::cout << YELLOW "Creating the three types of forms" RESET << std::endl;
		AForm *president = new PresidentialPardonForm("Kali");
		RobotomyRequestForm robots("Manfred");
		ShrubberyCreationForm shrub("Tree!");
		std::cout << "\n";

		std::cout << YELLOW "signing every form" RESET << std::endl;
		bill.signForm(*president);
		bill.signForm(robots);
		bill.signForm(shrub);
		std::cout << "\n";

		std::cout << YELLOW "Executing form PresidentialPardonForm" RESET << std::endl;
		bill.executeForm(*president);
		std::cout << "\n";
		std::cout << YELLOW "Executing form RobotomyRequestForm" RESET << std::endl;
		bill.executeForm(robots);
		std::cout << "\n";
		std::cout << YELLOW "Executing form ShrubberyCreationForm" RESET << std::endl;
		bill.executeForm(shrub);
		std::cout << "\n";
		delete president;
	}
	{
		std::cout << PURPLE "TEST: try to sign and execute with rank too low" RESET << std::endl;
		Bureaucrat nobody("that guy",150);
		ShrubberyCreationForm tree("ascii_art");
		std::cout << YELLOW "rank too low trying to sign form" RESET << std::endl;
		nobody.signForm(tree);
		std::cout << "\n";

		std::cout << YELLOW "ok rank trying to sign form" RESET << std::endl;
		Bureaucrat somebody("some guy", 145);
		somebody.signForm(tree);
		std::cout << "\n";

		std::cout << YELLOW "rank too low trying to execute form" RESET << std::endl;
		nobody.executeForm(tree);
		std::cout << "\n";
		std::cout << YELLOW "ok rank trying to execute form" RESET << std::endl;
		somebody.executeForm(tree);
		std::cout << "\n";
	}
	std::cout << std::endl;
	{
		std::cout << PURPLE "TEST: try to execute unsigned form" RESET << std::endl;
		Bureaucrat Jefrew("Jefrew", 1);
		PresidentialPardonForm pardon("william");

		std::cout << YELLOW "Try execute form before signing " RESET << std::endl;
		Jefrew.executeForm(pardon);
		std::cout << "\n";

		std::cout << YELLOW "Sign form" RESET << std::endl;
		Jefrew.signForm(pardon);
		std::cout << "\n";
		std::cout << YELLOW "Sign form again" RESET << std::endl;
		Jefrew.signForm(pardon);
		std::cout << "\n";
		std::cout << YELLOW "Try execute form again " RESET << std::endl;
		Jefrew.executeForm(pardon);
	}
	return 0;
}