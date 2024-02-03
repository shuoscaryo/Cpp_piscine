#pragma once
#include <iostream>
#include <stack>
#include <iterator>

template <typename T, class Ct = std::deque<T> > 
class MutantStack : public std::stack<T, Ct >
{
	public:
	// Public attributes
		typedef typename Ct::iterator iterator;
		typedef typename Ct::const_iterator const_iterator;
		typedef typename Ct::reverse_iterator reverse_iterator;
		typedef typename Ct::const_reverse_iterator const_reverse_iterator;

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

template <typename T, typename Ct>
MutantStack<T, Ct>::MutantStack(void):
	std::stack<T, Ct>()
{}

template <typename T, typename Ct>
MutantStack<T, Ct>::MutantStack(const MutantStack<T, Ct> & src):
	std::stack<T, Ct>(src)
{
	*this = src;
}

template <typename T, typename Ct>
MutantStack<T, Ct>::~MutantStack()
{}

template <typename T, typename Ct>
MutantStack<T, Ct> &MutantStack<T, Ct>::operator=(const MutantStack<T, Ct> &rhs)
{
	if (this != &rhs)
	{
		std::stack<T>::operator=(rhs);
	}
	return (*this);
}

template <typename T, typename Ct>
typename MutantStack<T, Ct>::iterator MutantStack<T, Ct>::begin()
{
	return (std::stack<T>::c.begin());
}

template <typename T, typename Ct>
typename MutantStack<T, Ct>::iterator MutantStack<T, Ct>::end()
{
	return (std::stack<T>::c.end());
}

template <typename T, typename Ct>
typename MutantStack<T, Ct>::reverse_iterator MutantStack<T, Ct>::rbegin()
{
	return (std::stack<T>::c.rbegin());
}

template <typename T, typename Ct>
typename MutantStack<T, Ct>::reverse_iterator MutantStack<T, Ct>::rend()
{
	return (std::stack<T>::c.rend());
}

template <typename T, typename Ct>
typename MutantStack<T, Ct>::const_iterator MutantStack<T, Ct>::begin() const
{
	return (std::stack<T>::c.begin());
}

template <typename T, typename Ct>
typename MutantStack<T, Ct>::const_iterator MutantStack<T, Ct>::end() const
{
	return (std::stack<T>::c.end());
}

template <typename T, typename Ct>
typename MutantStack<T, Ct>::const_reverse_iterator MutantStack<T, Ct>::rbegin() const
{
	return (std::stack<T>::c.rbegin());
}

template <typename T, typename Ct>
typename MutantStack<T, Ct>::const_reverse_iterator MutantStack<T, Ct>::rend() const
{
	return (std::stack<T>::c.rend());
}
