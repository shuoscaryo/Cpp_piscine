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

	std::cout << form1 << "\n" << veryImportant << "\n" << notVeryImportant
		<< "\n" << intern << std::endl;
	std::cout << "\n";
	
	std::cout << YELLOW "slave will try to sign the form" RESET << std::endl;
	intern.signForm(form1);
	std::cout << "\n";

	std::cout << YELLOW "Importantestn't will try to sign the form" RESET << std::endl;
	notVeryImportant.signForm(form1);
	std::cout << "\n";

	std::cout << YELLOW "Importantest will try to sign the form" RESET << std::endl;
	veryImportant.signForm(form1);
	std::cout << "\n";

	std::cout << YELLOW "Trying to create a form with grade too high" RESET << std::endl;
	try
	{
		Form badForm1("Very bad", 0 ,0);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n";

	std::cout << YELLOW "Trying to create a form with grade too low" RESET << std::endl;
	try
	{
		Form badForm1("Very bad2", 1000 , 10);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
