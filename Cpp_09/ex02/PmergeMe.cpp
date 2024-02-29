#include "PmergeMe.hpp"

template <typename T>
static void mergeSort(T &v)
{
	// Base case
	if (v.size() <= 1)
		return;

	// Recursive case
	T left;
	T right;
	size_t len = v.size();
	for (size_t i = 0; i < len / 2; i++)
		left.push_back(v[i]);
	for (size_t i = len / 2; i < len; i++)
		right.push_back(v[i]);
	mergeSort(left);
	mergeSort(right);

	// Merge
    typename T::iterator itLeft = left.begin();
    typename T::iterator itRight = right.begin();

    for (typename T::iterator it = v.begin(); it != v.end(); ++it) {
        if (itLeft == left.end())
            *it = *itRight++;
        else if (itRight == right.end())
            *it = *itLeft++;
        else if (itLeft->first < itRight->first)
            *it = *itLeft++;
        else
            *it = *itRight++;
    }
}

template <typename T>
static T generateSequence(size_t size, T v)
{
	(void)v;

	// Generate the min jacobsthal sequence that is greater than size
	T seq;
	seq.push_back(0);
	seq.push_back(1);
	for (size_t i = 2; seq[seq.size() - 1] < size; ++i)
		seq.push_back(seq[i - 1] + 2*seq[i - 2]);

	// Generate the jacobian sequence
	T jacobianSequence;
	for (size_t i = 1; i < seq.size(); i++)
	{
		for (size_t j = 0; seq[i] - j > seq[i - 1]; j++)
			jacobianSequence.push_back(seq[i] - j);
	}
	return jacobianSequence;
}

template <typename T>
static void insert(T &v, size_t num, size_t left, size_t right)
{
	// Special cases
	if (num < v[left])
		return (void) v.insert(v.begin(), num);
	if (num > v[right] && right < v.size() - 1)
		return (void) v.insert(v.begin() + right + 1, num);
	if (num > v[right] && right == v.size() - 1)
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

std::vector<size_t> PmergeMe::sortVector(std::vector<size_t> v)
{
	if (v.size() < 2)
	 	return v;

	// 1. Order the pairs (the last one is left alone if the length is odd)
	for (size_t i = 1; i < v.size(); i += 2)
		if (v[i - 1] < v[i])
			std::swap(v[i - 1], v[i]);

	// 2. Recursively sort the pairs
	std::vector<std::pair<size_t, size_t> > pairs;
	for (size_t i = 0; i < (v.size() - (v.size() % 2)); i += 2)
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

	// 4. Insert pendChain into mainChain
	// 4.1. Generate the jacobian sequence (the order in which the elements of pendChain will be inserted)
	std::vector<size_t> jacobianSequence = generateSequence(pendChain.size(), pendChain);
	// 4.2. The first element of pendChain can be added directly since main[0] > pend[0]
	mainChain.insert(mainChain.begin(),pendChain[0]);
	// 4.3. Insert the rest of the elements
	size_t inserted_count = 1;
	for (size_t i = 1; i < jacobianSequence.size(); i++)
	{
		size_t index = jacobianSequence[i] - 1;
		if (index > pendChain.size() - 1)
			continue;
		insert(mainChain, pendChain[index], 0, inserted_count + index - 1);
		inserted_count++;
	}
	// 4.4. If the length of the original vector was odd, insert the last element
	if (v.size() % 2)
		insert (mainChain, v[v.size() - 1], 0, mainChain.size() - 1);

	return mainChain;
}

std::deque<size_t> PmergeMe::sortDeque(std::deque<size_t> v)
{
	if (v.size() < 2)
	 	return v;

	// 1. Order the pairs (the last one is left alone if the length is odd)
	for (size_t i = 1; i < v.size(); i += 2)
		if (v[i - 1] < v[i])
			std::swap(v[i - 1], v[i]);

	// 2. Recursively sort the pairs
	std::deque<std::pair<size_t, size_t> > pairs;
	for (size_t i = 0; i < (v.size() - (v.size() % 2)); i += 2)
		pairs.push_back(std::make_pair(v[i], v[i + 1]));
	mergeSort(pairs);

	// 3. Create main chain and pend chain
	std::deque<size_t> mainChain;
	std::deque<size_t> pendChain;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		mainChain.push_back(pairs[i].first);
		pendChain.push_back(pairs[i].second);
	}

	// 4. Insert pendChain into mainChain
	// 4.1. Generate the jacobian sequence (the order in which the elements of pendChain will be inserted)
	std::deque<size_t> jacobianSequence = generateSequence(pendChain.size(), pendChain);
	// 4.2. The first element of pendChain can be added directly since main[0] > pend[0]
	mainChain.insert(mainChain.begin(),pendChain[0]);
	// 4.3. Insert the rest of the elements
	size_t inserted_count = 1;
	for (size_t i = 1; i < jacobianSequence.size(); i++)
	{
		size_t index = jacobianSequence[i] - 1;
		if (index > pendChain.size() - 1)
			continue;
		insert(mainChain, pendChain[index], 0, inserted_count + index - 1);
		inserted_count++;
	}
	// 4.4. If the length of the original vector was odd, insert the last element
	if (v.size() % 2)
		insert (mainChain, v[v.size() - 1], 0, mainChain.size() - 1);

	return mainChain;
}