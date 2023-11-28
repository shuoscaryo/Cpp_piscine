#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

#define YELLOW "\033[33m"
#define RESET "\033[0m"

int main()
{
	Intern Me;
	Bureaucrat boss("boss", 2);

	std::cout << YELLOW "Creating, signing and executing form presidential pardon" RESET << std::endl;
	AForm *form = Me.makeForm("presidential pardon", "pardoned");
	boss.signForm(*form);
	boss.executeForm(*form);
	delete form;
	std::cout << "\n";


	std::cout << YELLOW "Trying to create a wrong form" RESET << std::endl;
	form = Me.makeForm("wrong", "wrongest");
	std::cout << "\n";

	std::cout << YELLOW "Creating, signing and executing form robotomy request" RESET << std::endl;
	form = Me.makeForm("robotomy request", "robot");
	boss.signForm(*form);
	boss.executeForm(*form);
	delete form;
	std::cout << "\n";


	std::cout << YELLOW "Creating, signing and executing form shrubbery creation" RESET << std::endl;
	form = Me.makeForm("shrubbery creation", "shrubs");
	boss.signForm(*form);
	boss.executeForm(*form);
	delete form;
	return 0;
}