#pragma once
#include <cstddef>
#include <stdexcept>

template <typename T>
class Array
{
	public:
		Array(unsigned int n = 0);
		Array(const Array<T>& obj);
		~Array();

		size_t size() const;

		Array<T> &operator=(const Array<T>& obj);
		T &operator[](size_t i);

	private:
		T*		_array;
		size_t	_len;
};

template <typename T>
Array<T>::Array(unsigned int n)
{
	_array = new T[n];
	_len = n;
}

template <typename T>
Array<T>::Array(const Array<T>& obj)
{
	_array = new T[obj._len];
	for (size_t i= 0; i < obj._len; i ++)
		_array[i] = obj._array[i];
	_len = obj._len;
}

template <typename T>
Array<T>::~Array()
{
	delete [] _array;
}

template <typename T>
size_t	Array<T>::size() const
{
	return (_len);
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T>& obj)
{
	if (this != &obj)
	{
		delete [] _array;
		_array = new T[obj._len];
		for (size_t i= 0; i < obj._len; i ++)
			_array[i] = obj._array[i];
		_len = obj._len;
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](size_t i)
{
	if (i >= _len)
		throw std::runtime_error("Index out of bounds");
	return (_array[i]);
}
