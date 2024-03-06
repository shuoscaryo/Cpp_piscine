#include <iostream>
#include <vector>
#include <algorithm>
#include "PmergeMe.hpp"
#include <sstream>
#include <ctime>
#include <iomanip>

std::vector<size_t> getNumbers(char *argv)
{
	std::vector<size_t> v;
	std::string s(argv);
	std::istringstream iss(s);

	// Check for invalid characters
	if (s.find('-') != std::string::npos)
		throw std::invalid_argument("Error");
	// Get the numbers
	while (!iss.eof())
	{
		size_t temp;
		iss >> temp;
		if (iss.fail())
			throw std::invalid_argument("Error");
		v.push_back(temp);
	}

	return v;
}

template <typename T>
void printContainer(T v, const std::string &name = "")
{
	if (!name.empty())
		std::cout << name << ":\t";

	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << (i + 1< v.size()?" ":"");
	std::cout << std::endl;
}

int main(int argc, char **argv) {
	// Get the numbers from the command line
	std::vector<size_t> v;
	std::deque<size_t> d;
	for(int i = 1; i < argc; i++)
	{
		std::vector<size_t> temp;
		try
		{
			temp = getNumbers(argv[i]);
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
			return 1;
		}
		d.insert(d.end(), temp.begin(), temp.end());
		v.insert(v.end(), temp.begin(), temp.end());
	}

	if (d.size() == 0)
	{
		std::cout << "Error" << std::endl;
		return 1;
	}
	// Sort the numbers and measure the time
	clock_t aux = clock();
	std::vector<size_t> sortedV = PmergeMe::sortVector(v);
	double timeV = (clock() - aux) * 1000000.0 / CLOCKS_PER_SEC;
	aux = clock();
	std::deque<size_t> sortedD = PmergeMe::sortDeque(d);
	double timeD = (clock() - aux) * 1000000.0 / CLOCKS_PER_SEC;

	// print the sorted numbers
	printContainer(d, "Before");
	printContainer(sortedD, "After");
	std::cout << "Time to process a range of "<< v.size() << " elements with std::vector : "
		<< std::setprecision(5) << std::fixed << timeV << " us" << std::endl;
	std::cout << "Time to process a range of "<< v.size() << " elements with std::deque :  "
		<< std::setprecision(5) << std::fixed << timeD << " us" << std::endl;

	return 0;
}
