#include "Bureaucrat.hpp"
#include <iostream>

#define YELLOW "\033[33m"
#define RESET "\033[0m"

int main()
{
	std::cout << YELLOW << "Creating a bureaucrat of rank 0" << RESET <<std::endl;
	try
	{
		Bureaucrat bad1("bad1", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n";

	std::cout << YELLOW << "Creating a bureaucrat of rank 151" <<  RESET << std::endl;
	try
	{
		Bureaucrat bad2("bad2", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n";
	
	std::cout << YELLOW << "Creating a bureaucrat of rank 1" <<  RESET << std::endl;
	Bureaucrat allmight("All Might", 1);
	std::cout << allmight << "\n\n";

	std::cout << YELLOW << "Decrementing grade of All might" << RESET << std::endl;
	allmight.decrementGrade();
	std::cout << allmight << "\n\n";
	std::cout << YELLOW << "Incrementing grade of All might" << RESET << std::endl;
	allmight.incrementGrade();
	std::cout << allmight << "\n\n";

	std::cout << YELLOW << "Trying to increment grade of All might again" << RESET << std::endl;
	try
	{
		allmight.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n";

	std::cout << YELLOW << "Creating a bureaucrat of rank 150" <<  RESET << std::endl;
	Bureaucrat bottomG("crook", 150);
	std::cout << bottomG << "\n\n";
	std::cout << YELLOW << "Trying to decrement grade of crook" << RESET << std::endl;
	try
	{
		bottomG.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n";

	std::cout << YELLOW << "Accessors" << RESET << std::endl;
	std::cout << YELLOW << "\tbottomG.getName(): " << RESET << bottomG.getName() << std::endl;
	std::cout << YELLOW << "\tbottomG.getGrade(): " << RESET << bottomG.getGrade() << std::endl;
	return 0;
}
