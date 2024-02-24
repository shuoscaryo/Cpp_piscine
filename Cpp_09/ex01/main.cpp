#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	// Create a string with the arguments
	std::string operation;
	for (int i = 1; i < argc; ++i)
		operation += std::string(" ") + argv[i];

	// Calculate the operation
	try
	{
		std::cout << RPN::calculate(operation) << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
