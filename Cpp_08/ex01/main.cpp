#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

#define RESET   "\x1B[0m"
#define BLACK   "\x1B[30m"
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE    "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN    "\x1B[36m"
#define WHITE   "\x1B[37m"

int main()
{
	{
		std::cout << YELLOW << "SUBJECT TEST" << RESET << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << CYAN << "shortestSpan:"<<std::endl;
		std::cout << "\tExpected "<< GREEN << 2 << std::endl;
		std::cout << CYAN << "\tfunction " << GREEN << sp.shortestSpan() << std::endl;
		std::cout << CYAN << "longestSpan:"<<std::endl;
		std::cout << "\tExpected "<< GREEN << 14 << std::endl;
		std::cout << CYAN << "\tfunction " << GREEN << sp.longestSpan() << RESET << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << YELLOW << "ERROR CHECKING" << std::endl;
		std::cout << YELLOW << "1-addNumber to full list" << RESET << std::endl;
		std::cout << CYAN << "Creating span of " << GREEN << "N = 1" << CYAN << std::endl;
		Span sp(1);
		std::cout << "Trying to add a number" << std::endl;
		sp.addNumber(100);
		try
		{
			std::cout << "Trying to add another one" << std::endl;
			sp.addNumber(3);
		}
		catch(const std::exception& e)
		{
			std::cout << "Got exception: " << RED << e.what() << CYAN << std::endl;
		}
		std::cout << std::endl;
		std::cout << YELLOW << "2-Shortest and longest span in too short list" << RESET << std::endl;
		try
		{
			std::cout << CYAN << "Trying to execute shortestSpan on previous span of " << GREEN << "N = 1" << CYAN << std::endl;
			sp.shortestSpan();
		}
		catch(const std::exception& e)
		{
			std::cout << "Got exception: " << RED << e.what() << CYAN << std::endl;
		}
		try
		{
			std::cout << CYAN << "Trying to execute longestSpan on previous span of " << GREEN << "N = 1" << CYAN << std::endl;
			sp.longestSpan();
		}
		catch(const std::exception& e)
		{
			std::cout << "Got exception: " << RED << e.what() << CYAN << std::endl;
		}
		std::cout << std::endl;
		std::cout << YELLOW << "3-Adding a range of numbers too big" << RESET << std::endl;
		std::cout << CYAN << "Creating a list of " << GREEN << "100" << CYAN << " elements" << RESET << std::endl;
		std::list<int> list(100,3);
		try
		{
			std::cout << CYAN << "Trying to add the list to the span of " << GREEN << "N = 1" << CYAN << std::endl;
			sp.addRange(list.begin(),list.end());
		}
		catch(const std::exception& e)
		{
			std::cout << "Got exception: " << RED << e.what() << CYAN << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << YELLOW << "WORKING CASES" << std::endl;
		{
			std::cout << YELLOW << "1-Span with only 2 numbers" << std::endl;
			std::cout << CYAN << "Creating span containing " << GREEN << "(1,3)" << CYAN << std::endl;
			Span sp(2);
			sp.addNumber(1);
			sp.addNumber(3);
			std::cout << "shortestSpan is " << GREEN << sp.shortestSpan() << CYAN << std::endl;
			std::cout << "longestSpan is " << GREEN << sp.longestSpan() << CYAN << std::endl;
			std::cout << std::endl;
		}
		{
			std::cout << YELLOW << "2-Span with same numbers" << std::endl;
			std::cout << CYAN << "Creating span containing " << GREEN << "(4,4,4)" << CYAN << std::endl;
			Span sp(3);
			sp.addNumber(4);
			sp.addNumber(4);
			sp.addNumber(4);
			std::cout << "shortestSpan is " << GREEN << sp.shortestSpan() << CYAN << std::endl;
			std::cout << "longestSpan is " << GREEN << sp.longestSpan() << CYAN << std::endl;
			std::cout << std::endl;
		}
		{
			std::cout << YELLOW << "3-Adding range of numbers" << std::endl;
			std::cout << CYAN << "Creating a list containing " << GREEN << "(10,3,5,7,2)" << std::endl;
			std::list<int> list;
			list.push_back(10);
			list.push_back(3);
			list.push_back(5);
			list.push_back(7);
			list.push_back(2);
			std::cout << CYAN << "Creating a Span of " << GREEN << "N = 10" << CYAN << std::endl;
			Span sp(10);
			std::cout << CYAN << "Adding the list to Span with addRange" << std::endl;
			sp.addRange(list.begin(),list.end());
			std::cout << "shortestSpan is " << GREEN << sp.shortestSpan() << CYAN << std::endl;
			std::cout << "longestSpan is " << GREEN << sp.longestSpan() << CYAN << std::endl;
			std::cout << CYAN << "Creating a list containing " << GREEN << "(-10,-3,-5,-7,-2)" << std::endl;
			std::list<int> list2;
			list2.push_back(-10);
			list2.push_back(-3);
			list2.push_back(-5);
			list2.push_back(-7);
			list2.push_back(-2);
			std::cout << CYAN << "Adding the list to Span with addRange" << std::endl;
			sp.addRange(list2.begin(),list2.end());
			std::cout << "shortestSpan is " << GREEN << sp.shortestSpan() << CYAN << std::endl;
			std::cout << "longestSpan is " << GREEN << sp.longestSpan() << CYAN << std::endl;
			std::cout << std::endl;
		}
		{
			std::cout << YELLOW << "4-10k Numbers" << std::endl;
			std::cout << CYAN << "Creating a span with " << GREEN << "10k Numbers (0,...,10000)" << std::endl;
			size_t num = 10000;
			Span sp(num);
			for (size_t i = 0; i < num; i ++)
				sp.addNumber(i);
			std::cout << CYAN << "shortestSpan is " << GREEN << sp.shortestSpan() << std::endl;
			std::cout << CYAN << "longestSpan is " << GREEN << sp.longestSpan() << std::endl;
			std::cout << CYAN << "Creating a span with "<< GREEN << "10k random numbers" << std::endl;
			Span sp2(num);
			std::srand(std::time(0));
			for (size_t i = 0; i < num; i ++)
				sp2.addNumber(rand());
			std::cout << CYAN << "shortestSpan is " << GREEN << sp2.shortestSpan() << std::endl;
			std::cout << CYAN << "longestSpan is " << GREEN << sp2.longestSpan() << std::endl;
		}
	}
}