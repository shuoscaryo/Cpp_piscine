#pragma once
#include <iostream>
#include <map>

class BitcoinExchange
{
	public:
	// Constructors and destructor
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange & src);
		~BitcoinExchange();

	// Setters and getters
		
	// Member functions
		void run(const std::string & data) const;
		void readDatabase(const std::string & filename);

	// Operator overloads
		BitcoinExchange & operator=(const BitcoinExchange & rhs);

	protected:
	private:
	// Atributes
		bool _initialized;
		std::map<std::string, double> _Database;

	// Private member functions
		double getPrice(const std::string & date) const;

};
