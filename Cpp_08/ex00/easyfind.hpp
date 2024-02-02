#pragma once

template<typename T>
typename T::iterator easyfind(T &container, int num)
{
	typename T::iterator it;
	for (it = container.begin(); it != container.end(); ++it)
		if (*it == num)
			return it;
	return it;
}
