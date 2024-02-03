#pragma once
#include <iostream>
#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T> 
{
	public:
	// Public attributes
		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::const_iterator const_iterator;
		typedef typename std::deque<T>::reverse_iterator reverse_iterator;
		typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

	// Constructors and destructor
		MutantStack(void);
		MutantStack(const MutantStack & src);
		~MutantStack();

	// Setters and getters
		
	// Member functions
		iterator begin();
		iterator end();

		reverse_iterator rbegin();
		reverse_iterator rend();

		const_iterator begin() const;
		const_iterator end() const;

		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;

	// Operator overloads
		MutantStack & operator=(const MutantStack & rhs);
	
	protected:
	private:
};

template <typename T>
MutantStack<T>::MutantStack(void):
	std::stack<T>()
{}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> & src):
	std::stack<T>(src)
{
	*this = src;
}

template <typename T>
MutantStack<T>::~MutantStack()
{}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &rhs)
{
	if (this != &rhs)
	{
		std::stack<T>::operator=(rhs);
	}
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (std::stack<T>::c.end());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return (std::stack<T>::c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return (std::stack<T>::c.rend());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return (std::stack<T>::c.end());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
	return (std::stack<T>::c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
	return (std::stack<T>::c.rend());
}
