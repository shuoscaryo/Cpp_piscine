#pragma once
#include <iostream>

class ScalarConverter
{
	public:
		~ScalarConverter(void);
		static void convert(const std::string &str);
	protected:
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter & src);
		ScalarConverter & operator=(const ScalarConverter & rhs);
};

std::ostream &operator<<(std::ostream &os, const ScalarConverter &obj);
