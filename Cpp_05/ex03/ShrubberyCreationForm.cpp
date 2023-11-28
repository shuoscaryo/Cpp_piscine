#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
	AForm(target, 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & src):
	AForm(src)
{}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
	}
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::ofstream file((getName() + std::string("_shrubbery")).c_str(),std::ios::out);
	if (!file.is_open())
		throw ShrubberyCreationForm::FileError();
    file << "       ^\n";
    file << "      / \\\n";
    file << "     /   \\\n";
    file << "    /     \\\n";
    file << "   /       \\\n";
    file << "  /         \\\n";
    file << " /___________\\\n";
    file << "      | |" << std::endl;
}

const char *ShrubberyCreationForm::FileError::what() const throw()
{
	return ("Couldn't open file");
}
