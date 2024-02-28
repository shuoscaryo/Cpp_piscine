#pragma once
#include <iostream>
#include <vector>
#include <utility>

class PmergeMe
{
	public:
	// Constructors and destructor
		PmergeMe(void);
		PmergeMe(const PmergeMe & src);
		~PmergeMe();

	// Setters and getters
		
	// Member functions

		static std::vector<size_t> sort(std::vector<size_t> v);

	// Operator overloads
		PmergeMe & operator=(const PmergeMe & rhs);

	protected:
	private:
	// Atributes

	// Private member functions
		static void insert(std::vector<size_t> &v, size_t num, size_t left, size_t right);
		static void mergeSort(std::vector<std::pair<size_t, size_t> > &v);
		static std::vector<size_t> generateSequence(size_t size);
	// Friends <3
};
