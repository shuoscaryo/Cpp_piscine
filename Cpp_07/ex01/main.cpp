#include "iter.hpp"
#include <string>
#include <iostream>

void str_iter(size_t i, std::string &s)
{
	s += std::to_string(i);
}

int main()
{
	size_t len= 19;
	std::string *my_str = new std::string[len];

	for (size_t i = 0; i < len; i++)
		std::cout << "str["<<i<<"] = " << my_str[i] << std::endl;
	iter(my_str, len, str_iter);
	for (size_t i = 0; i < len; i++)
		std::cout << "str["<<i<<"] = " << my_str[i] << std::endl;
}