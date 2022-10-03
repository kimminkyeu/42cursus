#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

/*  NOTE: The Orthodox Canonical Class Form
 * (1) Default constructor: used internally to initialize objects and data members when no other value is available.
 * (2) Copy constructor: used in the implementation of call-by-value parameters.
 * (3) Copy assignment operator: used to assign one value to another. (for Deep Copy)
 * (4) Destructor: Invoked when an object is deleted. */

#include <iostream>

class Fixed {

private:
	static const int	_bits 	= 8;
	int					_value;

public:
	Fixed();
	Fixed(const Fixed& fixed);
	~Fixed();

	// copy assignment operator
	Fixed&	operator= (const Fixed& fixed);

	// Returns thr raw value of the fixed-point value.
	int		getRawBits(void) const;
	// Sets the raw value of the fixed-pointer number.
	void	setRawBits(int const raw);
};

#endif // FIXED_HPP
