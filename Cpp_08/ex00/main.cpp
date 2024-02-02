#include "easyfind.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <list>

#define RESET   "\x1B[0m"
#define BLACK   "\x1B[30m"
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE    "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN    "\x1B[36m"
#define WHITE   "\x1B[37m"

template<typename T>
static void printContainer(const T& container)
{
	typename T::const_iterator it;
	std::cout << "(";
	for (it = container.begin(); it != container.end();)
	{
		std::cout << *it;
		++it;
		if (it != container.end())
			std::cout << ", ";
	}
	std::cout << ")" << std::endl;
}

template<typename T>
static void test(T& container, int num, const std::string & type)
{

	typename T::iterator it = easyfind(container, num);
	if (it == container.end())
		std::cout << "* " << num << " is " << RED << "not" << CYAN << " in " << type << std::endl;
	else
		std::cout << "* " << num << " is in " << type << std::endl;	
}

int main()
{
	{
		std::string type = "vector";
		std::vector<int> v;
		v.push_back(1);
		v.push_back(10);
		v.push_back(-1);
		v.push_back(30);
		std::cout << YELLOW << "TESTING " << GREEN << type << YELLOW;
		std::cout << " with content: " << GREEN;
		printContainer(v);
		std::cout << CYAN;
		test(v, 1, type);
		test(v, -1, type);
		test(v, 30, type);
		test(v, 10, type);
		test(v, 5, type);
	}
	{
		std::string type = "set";
		std::set<int> v;
		v.insert(-123);
		v.insert(32);
		v.insert(56342);
		v.insert(756);
		std::cout << YELLOW << "TESTING " << GREEN << type << YELLOW;
		std::cout << " with content: " << GREEN;
		printContainer(v);
		std::cout << CYAN;
		test(v, -123, type);
		test(v, 32, type);
		test(v, 56342, type);
		test(v, 756, type);
		test(v, -23, type);
	}
	{
		std::string type = "list";
		std::list<int> v;
		v.push_back(-1234);
		v.push_back(324);
		v.push_back(563424);
		v.push_back(7564);
		std::cout << YELLOW << "TESTING " << GREEN << type << YELLOW;
		std::cout << " with content: " << GREEN;
		printContainer(v);
		std::cout << CYAN;
		test(v, -1234, type);
		test(v, 324, type);
		test(v, 563424, type);
		test(v, 7564, type);
		test(v, -234, type);
	}
	return 0;
}