#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

#define YELLOW "\033[33m"
#define RESET "\033[0m"

int main()
{
	std::cout << YELLOW "Creating an ok form with 3 bureaucrats" RESET << std::endl;
	Form form1("Very ok", 2, 1);
	Bureaucrat veryImportant("Importantest", 1);
	Bureaucrat notVeryImportant("importantestn't", 2);
	Bureaucrat intern("slave", 150);

	std::cout << "\n" << form1 << "\n" << veryImportant << "\n" << notVeryImportant
		<< "\n" << intern << std::endl;
	
	std::cout << YELLOW "slave will try to sign the form" RESET << std::endl;
	intern.signForm(form1);
	std::cout << "\n";

	std::cout << YELLOW "Importantestn't will try to sign the form" RESET << std::endl;
	notVeryImportant.signForm(form1);
	std::cout << "\n";

	std::cout << YELLOW "Importantest will try to sign the form" RESET << std::endl;
	veryImportant.signForm(form1);
	std::cout << "\n";

	return 0;
}