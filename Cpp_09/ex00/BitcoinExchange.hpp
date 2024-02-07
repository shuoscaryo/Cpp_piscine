#pragma once
#include <iostream>

class BitcoinExchange
{
	public:
	// Constructors and destructor
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange & src);
		~BitcoinExchange();

	// Setters and getters
		
	// Member functions

	// Operator overloads
		BitcoinExchange & operator=(const BitcoinExchange & rhs);
	protected:
	private:

	friend std::ostream &operator<<(std::ostream &os, const BitcoinExchange &obj);
};

std::ostream &operator<<(std::ostream &os, const BitcoinExchange &obj);
