#pragma once

#include <cstddef>

template<typename T>
void iter(T *array, size_t len, void (*f)(size_t,T&))
{
	if (!f || !array)
		return ;
	for (size_t i = 0; i < len; i++)
		f(i,array[i]);
}