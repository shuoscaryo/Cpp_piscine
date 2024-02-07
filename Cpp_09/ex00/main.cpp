#include <iostream>
#include "BitcoinExchange.hpp"
#include <fstream>
#include <map>

std::string getNextLine(std::string& str)
{
	size_t pos = str.find('\n');
	std::string ret = str.substr(0, pos);
	if (pos != std::string::npos && pos + 1 < str.size())
		str = str.substr(pos + 1);
	else
		str = "";
	return ret;
}

int main(int argc, char **argv)
{
	// check if there are 2 arguments
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

	// try to open the file and save it as a string
	std::ifstream fd(argv[1]);
	if (!fd.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	std::string file;
	fd >> file;

	// Load the database
	std::map<std::string, int> db = loadDatabase("data.csv");

	return 0;
}
