#pragma once
#ifndef CONVERTER_HPP
# define CONVERTER_HPP

#include <iostream>
#include <string>
#include <cctype> // isprint
#include <cstdlib> // atoi, atof, strtol
#include <iomanip> // set precision
#include <limits.h> // max numerical digits
#include <stdint.h> // for int42_t

typedef enum e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	IMPOSSIBLE, // Unkown type
	INT_OVERFLOW, // Overflow
	INFINITE_POSITIVE, // +inf
	INFINITE_NEGATIVE, // -inf
}	t_type;

class Converter
{

private:
	union {
		char 	_valueChar;
		int		_valueInt;
		float 	_valueFloat;
		double 	_valueDouble;

		int64_t	_valueBits;
	};

	int 	_precision;
	t_type	_actualTypeInfo;

	static t_type	_getActualType(const std::string& str);

public:
	Converter();
	~Converter();
	Converter(const Converter& converter);
	Converter& operator= (const Converter& converter);
	Converter(const std::string& str);

	void printToChar();
	void printToInt();
	void printToFloat();
	void printToDouble();
};

#endif // CONVERTER_HPP
