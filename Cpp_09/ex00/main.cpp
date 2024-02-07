#include <iostream>
#include "BitcoinExchange.hpp"
#include <fstream>
#include <map>
#include <exception>

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

std::string trim(const std::string& str, const std::string & charset = " \t\n\r\f\v")
{
    size_t first = str.find_first_not_of(charset);
    if (std::string::npos == first)
        return str;
    size_t last = str.find_last_not_of(charset);
    return str.substr(first, (last - first + 1));
}

std::string readFile(const std::string & file)
{
	// Try to open the file
	std::ifstream fd(file);
	if (!fd.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		throw std::runtime_error("");
	}

	// save the file into a string
	std::string ret;
	fd >> ret;
	return ret;
}

std::map<std::string,size_t> loadDatabase(const std::string & file)
{
	//main handles the exception
	std::string fileStr = readFile(file);

	while (!fileStr.empty())
	{
		std::string line = getNextLine(fileStr);
		size_t pos 
	}
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
	std::string file;
	try { file = readFile(argv[1]); }
	catch (const std::exception & e) { return 1; }

	// Load the database
	std::map<std::string, size_t> db;
	try { loadDatabase("data.csv"); }
	catch (const std::exception & e) { return 1; }

	return 0;
}
