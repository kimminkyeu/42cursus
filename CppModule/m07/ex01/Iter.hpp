#pragma once
#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef> // for size_t

template <typename T>
void iter(T* arr, size_t length, void (*f)(T&))
{
	for (size_t i=0; i<length; i++)
	{
		f(arr[i]);
	}
}

template <typename T>
void increment(T& t)
{
	t += 1;
}

#endif // ITER_HPP
