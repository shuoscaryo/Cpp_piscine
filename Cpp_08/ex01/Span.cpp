#include "Span.hpp"
#include <iterator>

Span::Span(int N):
	_N(N), _isSorted(false), _listLen(0)
{}

Span::Span(const Span & src)
{
	*this = src;
}

Span::~Span()
{}

void Span::addNumber(int num)
{
	// If max number of elements has beend reached, throw an exception
	if (_listLen >= _N)
		throw std::runtime_error("[Span::addNumber] Max number of elements reached");

	// Save the last element of the list to compare it with the new number
	int last_num = _list.back();
	// Add the new number at the end of the list (O(1) complexity)
	_list.push_back(num);
	// If the number added is smaller than the last previous number, the list is unsorted
	if (num < last_num)
		_isSorted = false;
	++_listLen;
}

void Span::addRange(std::list<int>::iterator first, std::list<int>::iterator last)
{
	unsigned int len = std::distance(first,last);
	if (len > _N - _listLen)
		throw std::runtime_error("[Span::addRange] Cannot add elements, insufficent space");
	
	_list.insert(_list.end(),first,last);
	_isSorted = false;
	_listLen += len;
}

size_t Span::shortestSpan()
{
	if (_listLen < 2)
		throw std::runtime_error("[Span::shortestSpan] Insufficent number of elements");

	if (!_isSorted)
		_list.sort();

	std::list<int>::iterator it;
	size_t min = *(++_list.begin()) - _list.front();
	int last = _list.front();
	for (it = ++++_list.begin(); it != _list.end(); ++it)
	{
		if ((size_t)(*it) - (size_t)last < min)
			min = *it - last;
		last = *it;
	}

	return min;
}

size_t Span::longestSpan()
{
	if (_listLen < 2)
		throw std::runtime_error("[Span::longestSpan] Insufficent number of elements");

	if (!_isSorted)
		_list.sort();


	return (size_t)_list.back() - (size_t)_list.front();
}

Span &Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		_N = rhs._N;
		_list = rhs._list;
		_isSorted = rhs._isSorted;
		_listLen = rhs._listLen;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Span &obj)
{
	(void)obj;
	return (os);
}
