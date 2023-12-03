#pragma once

#include <cstddef>

template<typename T, typename J>
void iter(T *array, size_t len, void (*f)(J&))
{
	if (!f || !array)
		return ;
	for (size_t i = 0; i < len; i++)
		f(array[i]);
}
