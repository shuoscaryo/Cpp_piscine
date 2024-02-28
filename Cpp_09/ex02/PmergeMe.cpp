#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{}

PmergeMe::PmergeMe(const PmergeMe & src)
{
	*this = src;
}

PmergeMe::~PmergeMe()
{}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs)
	{
		// copy
	}
	return (*this);
}

void PmergeMe::insert(std::vector<size_t> &v, size_t num, size_t left, size_t right)
{
	// Special cases
	if (num < v[left])
		return (void) v.insert(v.begin(), num);
	if (num > v[right])
		return (void) v.push_back(num);

	// Binary search
	for (size_t i = (left + right) / 2; right - left > 1; i = (left + right) / 2)
	{
		if (v[i] < num)
			left = i;
		else
			right = i;
	}

	// Insert at the right position
	v.insert(v.begin() + right, num);
}

std::vector<size_t> PmergeMe::sort(std::vector<size_t> v)
{
	// 1. Order the pairs (the last one is left alone if the length is odd)
	for (size_t i = 1; i < v.size(); i += 2)
		if (v[i - 1] < v[i])
			std::swap(v[i - 1], v[i]);

	// 2. Recursively sort the pairs
	std::vector<std::pair<size_t, size_t> > pairs;
	for (size_t i = 0; i < v.size(); i += 2)
		pairs.push_back(std::make_pair(v[i], v[i + 1]));
	mergeSort(pairs);

	// 3. Create main chain and pend chain
	std::vector<size_t> mainChain;
	std::vector<size_t> pendChain;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		mainChain.push_back(pairs[i].first);
		pendChain.push_back(pairs[i].second);
	}
	if (v.size() % 2)
		pendChain.push_back(v[v.size() - 1]);

	// 4. Insert pendChain into mainChain
	// 4.1. Generate the jacobian sequence (the order in which the elements of pendChain will be inserted)
	std::vector<size_t> jacobianSequence = generateSequence(pendChain.size());
	// 4.2. The first element of pendChain can be added directly since main[0] > pend[0]
	mainChain.insert(mainChain.begin(),pendChain[0]);
	// 4.3. Insert the rest of the elements
	for (size_t i = 1; i < pendChain.size(); i++)
	{
		size_t index = jacobianSequence[i] - 1;
		if (index > pendChain.size() - 1)
			continue;
		insert(mainChain, pendChain[index], 0, i + index - 1);
	}

	return mainChain;
}

void PmergeMe::mergeSort(std::vector<std::pair<size_t,size_t> > &v)
{
	// Base case
	if (v.size() <= 1)
		return;

	// Recursive case
	std::vector<std::pair<size_t, size_t> > left;
	std::vector<std::pair<size_t, size_t> > right;
	size_t len = v.size();
	for (size_t i = 0; i < len / 2; i++)
		left.push_back(v[i]);
	for (size_t i = len / 2; i < len; i++)
		right.push_back(v[i]);
	mergeSort(left);
	mergeSort(right);

	// Merge
	size_t l = 0;
	size_t r = 0;
	for (size_t i = 0; i < len; i++)
	{
		if (l == left.size())
			v[i] = right[r++];
		else if (r == right.size())
			v[i] = left[l++];
		else if (left[l].first < right[r].first)
			v[i] = left[l++];
		else
			v[i] = right[r++];
	}
}

std::vector<size_t> PmergeMe::generateSequence(size_t size)
{
	// Generate the min jacobsthal sequence that is greater than size
	std::vector<size_t> seq;
	seq.push_back(0);
	seq.push_back(1);
	for (size_t i = 2; seq[seq.size() - 1] < size; ++i)
		seq.push_back(seq[i - 1] + 2*seq[i - 2]);

	// Generate the jacobian sequence
	std::vector<size_t> jacobianSequence;
	for (size_t i = 1; i < seq.size(); i++)
	{
		for (size_t j = 0; seq[i] - j > seq[i - 1]; j++)
			jacobianSequence.push_back(seq[i] - j);
	}
	return jacobianSequence;
}