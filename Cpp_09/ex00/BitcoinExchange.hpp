#pragma once
#include <iostream>
#include <map>
class BitcoinExchange
{
	public:
	// Constructors and destructor
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange & src);
		~BitcoinExchange();

	// Setters and getters
		
	// Member functions
	
		void readDatabase(const std::string & filename);

	// Operator overloads
		BitcoinExchange & operator=(const BitcoinExchange & rhs);

	protected:
	private:
	// Atributes

		std::map<std::string, double> _Database;

	// Private member functions
	friend int main();
};
