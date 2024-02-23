#include <iostream>
#include "BitcoinExchange.hpp"
#include <fstream>
#include <map>
#include <exception>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	// check if there are 2 arguments
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

	try
	{
		BitcoinExchange btc("data.csv");
		btc.run(argv[1]);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}

	return 0;
}
