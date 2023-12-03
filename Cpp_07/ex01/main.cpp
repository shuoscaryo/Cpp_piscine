#include "iter.hpp"
#include <string>
#include <iostream>

#define PURPLE "\033[1;35m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

void addindex(std::string &s)
{
	s += "_index";
}

template <typename T>
void square(T &f)
{
	f *= f;
}

int main()
{
	size_t len= 5;

	std::cout << YELLOW "Creating a string array of size " << len << RESET << std::endl;
	std::string *my_str = new std::string[len];
	for (size_t i = 0; i < len; i++)
		std::cout << "str["<<i<<"] = \"" << my_str[i] << "\""<<std::endl;
	std::cout << std::endl;
	std::cout << YELLOW "Using iter with addindex" RESET << std::endl;
	iter(my_str, len, addindex);
	for (size_t i = 0; i < len; i++)
		std::cout << "str["<<i<<"] = \"" << my_str[i] << "\""<<std::endl;
	delete [] my_str;
	std::cout << std::endl;

	std::cout << YELLOW "Trying iter on NULL pointer" RESET << std::endl;
	my_str = NULL;
	iter(my_str, len, addindex);
	std::cout << std::endl;


	float *floats = new float[len];
	for (size_t i = 0; i < len; i++)
		floats[i] = i;
	for (size_t i = 0; i < len; i++)
		std::cout << "floats["<<i<<"]=" << floats[i] << std::endl;
	std::cout << std::endl;
	std::cout << YELLOW "Using iter with square template function" RESET << std::endl;
	iter(floats, len, square<float>);
	for (size_t i = 0; i < len; i++)
		std::cout << "floats["<<i<<"]=" << floats[i] << std::endl;
	delete [] floats;
}