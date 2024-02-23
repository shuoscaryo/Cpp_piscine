#pragma once
#include <iostream>
#include <map>

class BitcoinExchange
{
	public:
	// Constructors and destructor
		BitcoinExchange(const std::string & database = "data.csv");
		BitcoinExchange(const BitcoinExchange & src);
		~BitcoinExchange();

	// Setters and getters
		
	// Member functions
		void run(const std::string & data) const;

	// Operator overloads
		BitcoinExchange & operator=(const BitcoinExchange & rhs);

	protected:
	private:
	// Atributes

		std::map<std::string, double> _Database;

	// Private member functions
		void readDatabase(const std::string & filename);
};
