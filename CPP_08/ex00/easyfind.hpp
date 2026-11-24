#pragma once

#include <iostream>
#include <stdexcept>
#include <array>
#include <list>
#include <vector>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int num) // for vectors or lists
{
	typename T::iterator found = std::find(container.begin(), container.end(), num);
	if (found == container.end())
		throw std::out_of_range("Value is not in container");
	return found;
}

template <typename T, std::size_t N>
T *easyfind(T (&array)[N], int num) // for arrays
{
	T *found = std::find(array, array + N, num);
	if (found == array + N)
		throw std::out_of_range("Value is not in container");
	return found;
}