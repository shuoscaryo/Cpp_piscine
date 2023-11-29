#include "ScalarConverter.hpp"
#include <limits>
#include <cctype>
#include <cstdlib>
#include <string>
#include <cmath>
#include <iomanip>

ScalarConverter::ScalarConverter(void)
{}

ScalarConverter::ScalarConverter(const ScalarConverter & src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter(void)
{}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
	if (this != &rhs)
	{
		// copy
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const ScalarConverter &obj)
{
	(void)obj;
	return (os);
}
///////////////////////////////////////////////////////////////////////////////

enum Type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	UNKNOWN
};

bool isChar(const std::string &str)
{
	if (str.length() == 1 && !std::isdigit(str[0]))
		return true;
	return false;
}

bool intOverflow(long long int num)
{
	long long int isNegative = (num < 0);

	if (isNegative && num < std::numeric_limits<int>::min())
		return true;
	if (!isNegative && num > std::numeric_limits<int>::max())
		return true;
	return false;
}

bool isInt(const std::string &str)
{
	size_t len = str.length();
	size_t i = 0;
	long long int val = 0;
	bool isNegative = false;

	if (len == (str[0] == '-' || str[0] == '+'))
		return false;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			isNegative = true;
		i++;
	}
	for (i = i; i < len; i++)
	{
		val = val * 10 + str[i] - '0';
		if (intOverflow(val * (-1 * (isNegative) + !isNegative)))
			return false;
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool isFloat(const std::string &str)
{
	size_t len = str.length();
	bool foundDot = false;

	if (str == "+inff" || str == "-inff" || str == "nanf")
		return true;
	if (len == (size_t)(str[0] == '-' || str[0] == '+') + 1) //str can have a sign and must have a dot
		return false;
	if (str[0] != '-' && str[0] != '+' && !std::isdigit(str[0]))
		return false;
	if ((str[0] == '-' || str[0] == '+') && str[1] == '.') //if there is '.' after +-
		return false;
	for (size_t i = 1; i < len - 1; i++)
	{
		if (str[i] == '.')
		{
			if (foundDot)   //if dot has already been found earlier
				return false;
			foundDot = true;
		}
		else if (!std::isdigit(str[i]))
			return false;
	}
	if (str[len - 1] != 'f') // if string doesn't end in 'f'
		return false;
	return foundDot;  //return true if there is '.' and false otherwise
}

bool isDouble(const std::string &str)
{
	size_t len = str.length();
	bool foundDot = false;

	if (str == "+inf" || str == "-inf" || str == "nan")
		return true;
	if (len == (size_t)(str[0] == '-' || str[0] == '+') + 1) //str can have a sign and must have a dot
		return false;
	if (str[0] != '-' && str[0] != '+' && !std::isdigit(str[0]))
		return false;
	if ((str[0] == '-' || str[0] == '+') && str[1] == '.') //if there is '.' after +-
		return false;
	for (size_t i = 1; i < len; i++)
	{
		if (str[i] == '.')
		{
			if (foundDot)   //if dot has already been found earlier
				return false;
			foundDot = true;
		}
		else if (!std::isdigit(str[i]))
			return false;
	}
	return foundDot;  //return true if there is '.' and false otherwise
}

Type getType(const std::string &str)
{
	if (isChar(str))
		return CHAR;
	if (isInt(str))
		return INT;
	if (isFloat(str))
		return FLOAT;
	if (isDouble(str))
		return DOUBLE;
	return UNKNOWN;
}

void printChar(const std::string &str)
{
	char a = str[0];
	if (std::isprint(a))
		std::cout << "char: '" << a << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(a) << std::endl;
	std::cout << "float: " << static_cast<float>(a) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(a) << std::endl;
}

void printInt(const std::string &str)
{
	int a = std::atoi(str.c_str());
	if (isascii(a) && std::isprint(a))
		std::cout << "char: '" << static_cast<char>(a) << "'" << std::endl;
	else if (isascii(a))
		std::cout << "char: Non displayable" << std::endl;
	else
	std::cout << "int: " << a << std::endl;
	std::cout << "float: " << static_cast<float>(a) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(a) << std::endl;
}

void printFloat(const std::string &str)
{
	float a = std::atof(str.c_str());
	bool overflow = intOverflow(static_cast<long long int>(a));
	int b = static_cast<int>(a);
	if(overflow || std::isnan(a) || std::isinf(a) || !isascii(b))
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(b))
		std::cout << "char: '" << static_cast<char>(a) << "'" <<std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (overflow || std::isnan(a) || std::isinf(a))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << b << std::endl;
	std::cout << "float: " << a << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(a) << std::endl;
}

void printDouble(const std::string &str)
{
	double a = std::atof(str.c_str()); //atof returns double
	bool overflow = intOverflow(static_cast<long long int>(a));
	int b = static_cast<int>(a);
	if(overflow || std::isnan(a) || std::isinf(a) || !isascii(b))
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(b))
		std::cout << "char: '" << static_cast<char>(a) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (overflow || std::isnan(a) || std::isinf(a))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << b << std::endl;
	std::cout << "float: " << static_cast<float>(a) << "f" << std::endl;
	std::cout << "double: " << a << std::endl;
}

void printUnknown()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
	Type type = getType(str);

	std::cout << std::fixed << std::setprecision(1);
	switch(type)
	{
		case (CHAR):
			printChar(str);
			break;
		case (INT):
			printInt(str);
			break;
		case (FLOAT):
			printFloat(str);
			break;
		case (DOUBLE):
			printDouble(str);
			break;
		default:
			printUnknown();
	}
}
