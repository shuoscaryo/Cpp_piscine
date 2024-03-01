#include "BitcoinExchange.hpp"
#include <sstream>
#include <fstream>
#include <iostream>
#include <map>
#include <ctime>

static double stod(const std::string & str)
{
	std::istringstream iss(str);
	double num;
	iss >> num;
	return num;
}

static std::string trim(const std::string& str, const std::string & charset = " \t\n\r\f\v")
{
    size_t first = str.find_first_not_of(charset);
    if (std::string::npos == first)
        return str;
    size_t last = str.find_last_not_of(charset);
    return str.substr(first, (last - first + 1));
}

static bool isNumber(const std::string & str)
{
	std::istringstream iss(str);
	double num;
	iss >> num;
	return !iss.fail() && iss.eof();
}

static bool isDate(const std::string & str)
{
	struct tm tp;
	char *ptr = strptime(str.c_str(), "%Y-%m-%d", &tp);
	return (ptr != NULL && *ptr == '\0');
}

BitcoinExchange::BitcoinExchange():
	_initialized(false)
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange()
{}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
	{
		_Database = rhs._Database;
		_initialized = rhs._initialized;
	}
	return (*this);
}

void BitcoinExchange::run(const std::string & data) const
{
	std::string line;

	// Check if readDatabase was called
	if (!_initialized)
		throw std::runtime_error("Internal Error: database not initialized.");

	// Open the file
	std::ifstream file(data.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");

	// Skip first linez which contains headers
	std::getline(file, line, '\n');

	// Loop through the rest of the database saving date-value pairs in "_Database" map
	while(!file.eof())
	{
		// Read a new line
		getline(file, line, '\n');

		// Skip the line if it's empty
		if(line.empty())
			continue; 

		// Find the position of the separator between date and value
		size_t separator_pos = line.find('|');
		if (separator_pos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		// Get the key and value as a string
		std::string key = trim(line.substr(0, separator_pos));
		std::string value = trim(line.substr(separator_pos + 1));

		// If key is not a date or value is not a number skip it
		if (!isDate(key) || !isNumber(value))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		
		// Convert the value to double
		double num = ::stod(value);
		if (num > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		else if (num < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}

		// Print the result
		std::cout << key << " => " << value << " = " << num * getPrice(key) << std::endl;
	}
}

void BitcoinExchange::readDatabase(const std::string & filename)
{
	std::string line;
	std::string ERROR_DATABASE = "Error: invalid database content";

	// Open the file
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open database file");

	// Skip first line which contains headers
	std::getline(file, line, '\n');

	// Loop through the rest of the database saving date-value pairs in "_Database" map
	while(!file.eof())
	{
		// Read a new line
		getline(file, line, '\n');

		// Skip the line if it's empty
		if(line.empty())
			continue; 

		// Find the position of the separator between date and value
		size_t separator_pos = line.find(',');
		if (separator_pos == std::string::npos)
			throw std::runtime_error(ERROR_DATABASE);

		// Get the key and value as a string
		std::string key = trim(line.substr(0, separator_pos));
		std::string value = trim(line.substr(separator_pos + 1));

		// If key is not a date or value is not a number or the key is repeated throw error
		if (!isDate(key) || !isNumber(value) || _Database.count(key) == 1)
			throw std::runtime_error(ERROR_DATABASE);
		
		// Convert the value to double and save key-value pair
		_Database[key] = ::stod(value);
	}

	// If the database is empty throw error
	if (_Database.empty())
		throw std::runtime_error(ERROR_DATABASE);

	// Set the initialized flag to true
	_initialized = true;
}

double BitcoinExchange::getPrice(const std::string & date) const
{
	// Check if readDatabase was called
	if (!_initialized)
		throw std::runtime_error("Internal Error: database not initialized.");

	// If the date is in the database return the value
	if (_Database.count(date) == 1)
		return _Database.at(date);

	// Otherwise return the closest value
	// Find the first element with a key not less than date
	std::map<std::string,double>::const_iterator it;
	for (it = _Database.begin(); it != _Database.end() && it->first < date; ++it)
		;

	// If the date is before the first element return the first element
	if (it == _Database.begin())
		return it->second;
	// Otherwise return the closest smaller element (it.end() will return the last element)
	return (--it)->second;
}
