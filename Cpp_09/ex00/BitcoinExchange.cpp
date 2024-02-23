#include "BitcoinExchange.hpp"
#include <sstream>
#include <fstream>
#include <iostream>
#include <map>
#include <ctime>

static size_t datetonum(const std::string& dateStr) {
    // Parse the date string
    struct tm tm;
    strptime(dateStr.c_str(), "%Y-%m-%d", &tm);

    // Convert the time structure to a time value
    std::time_t timeValue = std::mktime(&tm);

    // Convert the time value to size_t representation
    return static_cast<size_t>(timeValue);
}

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

BitcoinExchange::BitcoinExchange(const std::string & database)
{
	readDatabase(database);
}

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
	}
	return (*this);
}

void BitcoinExchange::run(const std::string & data) const
{
	std::ifstream file(data.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");

	std::string line;
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

		double price;
		if (_Database.count(key) == 1)
			price = _Database.at(key);
		else
		{
			std::map<std::string,double>::const_iterator it;
			for (it = _Database.begin(); it != _Database.end() && it->first < key; ++it)
				;

			if (it == _Database.begin())
				price = it->second;
			else if (it == _Database.end())
				price = _Database.rbegin()->second;
			else
			{
				std::map<std::string,double>::const_iterator it2 = it--;
				if(datetonum(it2->first) - datetonum(key) <= datetonum(key) - datetonum(it->first))
					it = it2;
				price = it->second;
			}
		}
		std::cout << key << " => " << value << " = " << num * price << std::endl;
	}
}

void BitcoinExchange::readDatabase(const std::string & filename)
{
	std::string ERROR_DATABASE = "Error: invalid database content";
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error(ERROR_DATABASE);

	std::string line;
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

	if (_Database.empty())
		throw std::runtime_error(ERROR_DATABASE);
}
