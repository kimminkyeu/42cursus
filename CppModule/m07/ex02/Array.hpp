#pragma once
#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>

template<typename T>
class Array
{
private:
	T* 		_data;
	size_t	_length;

public:
	// Creates an empty array.
	Array()
		:_data(NULL), _length(0)
	{}

	~Array()
	{
		delete[] _data;
	}

	// Creates an array of n elements initialized by default
	Array(unsigned int n)
	{
		if (n == 0)
		{
			_data = NULL;
		}
		else
		{
			_data = new T[n];
		}
		_length = n;
	}

	Array(const Array& array)
		:_length(0), _data(NULL)
	{
		// (*this).operator=(array);
		(*this) = array;
	}

	T& operator[] (const int& index) const
	{
		if (index < 0 || index >= _length)
			throw(ExceptionOutOfBound());
		return (_data[index]);
	}

	Array& operator= (const Array& array)
	{
		if (this == &array)
			return (*this);

		delete[] this->_data;
		_data = new T[array._length];
		for (size_t i=0; i<array._length; i++)
		{
			(_data)[i] = array._data[i];
		}
		this->_length = array._length;
		return (*this);
	}

	size_t size() const
	{
		return _length;
	}

	class ExceptionOutOfBound : public std::exception
	{
		virtual const char* what() const throw()
		{
			return ("Exception: Index out of bound");
		}
	};
};

#endif // Array.hpp
