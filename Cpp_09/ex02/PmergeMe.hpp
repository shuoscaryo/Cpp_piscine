#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <deque>

class PmergeMe
{
	public:
	// Constructors and destructor

		PmergeMe(void);
		PmergeMe(const PmergeMe & src);
		~PmergeMe();

	// Setters and getters
		
	// Member functions

		static std::vector<size_t> sortVector(std::vector<size_t> v);
		static std::deque<size_t> sortDeque(std::deque<size_t> v);

	// Operator overloads
		PmergeMe & operator=(const PmergeMe & rhs);

	protected:
	private:
	// Atributes

	// Private member functions

	// Friends <3
};
