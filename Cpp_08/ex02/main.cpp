#include "MutantStack.hpp"
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

int main()
{
	{
		std::cout << YELLOW << "SUBJECT TEST" << RESET << std::endl;
		std::cout << CYAN << "Creating MutantStack" << std::endl;
		MutantStack<int> mstack;
		std::cout << CYAN << "Pushing elements " << GREEN << "17" << CYAN " and " << GREEN << "5" << std::endl;
		mstack.push(17);
		mstack.push(5);
		std::cout << CYAN << "top: "  << GREEN << mstack.top() << std::endl;
		std::cout << CYAN << "Popping one element" << std::endl;
		mstack.pop();
		std::cout << CYAN << "size: " << GREEN << mstack.size() << std::endl;
		std::cout << CYAN << "Pushing elements " << GREEN << "(3, 5, 737, 0)" << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		std::cout << CYAN << "Creating iterators and looping through stack" << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << GREEN;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << CYAN << "Creating an std::stack from a Mutant stack" << std::endl;
		std::stack<int> s(mstack);
		std::cout << std::endl;
	}
	{
		std::cout << YELLOW << "SAME TEST WITH A LIST" << RESET << std::endl;
		std::cout << CYAN << "Creating list" << std::endl;
		std::list<int> mstack;
		std::cout << CYAN << "Pushing elements " << GREEN << "17" << CYAN " and " << GREEN << "5" << std::endl;
		mstack.push_back(5);
		mstack.push_back(17);

		std::cout << CYAN << "top: " << GREEN << mstack.back() << std::endl;
		std::cout << CYAN << "Popping one element" << std::endl;
		mstack.pop_back();
		std::cout << CYAN << "size: " << GREEN << mstack.size() << std::endl;
		std::cout << CYAN << "Pushing elements " << GREEN << "(3, 5, 737, 0)" << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);
		std::cout << CYAN << "Creating iterators and looping through stack" << std::endl;
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << GREEN;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		return 0;
	}
}
