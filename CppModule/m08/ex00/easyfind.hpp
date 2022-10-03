#pragma once
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm> // std::find
#include <exception>

/**
 * ? Writing custom Iterator (Cherno's cpp youtube)
 * https://www.youtube.com/watch?v=F9eDv-YIOQ0 */

// [typename] : telling compiler that T::iterator is a type.
template<typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator iter = std::find(container.begin(), container.end(), value);
	if (iter == container.end())
		throw (std::runtime_error("value not found"));
	return (iter);
}

#endif // Easyfind.hpp
