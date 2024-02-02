#pragma once
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T &container, int num)
{
	return std::find(container.begin(), container.end(), num);
}
