#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

/*  NOTE:  The Orthodox Canonical Class Form
 * (1) Default constructor: used internally to initialize objects and data members when no other value is available.
 * (2) Copy constructor: used in the implementation of call-by-value parameters.
 * (3) Copy assignment operator: used to assign one value to another. (for Deep Copy)
 * (4) Destructor: Invoked when an object is deleted. */

// Fixed Point number : https://www.youtube.com/watch?v=ZMsrZvBmQnU

#include <iostream>
#include <cmath>								// for roundf

class Fixed {

private:
	static const int	_bits = 8;
	int					_value;

public:
	// ex00
	Fixed(); 									// default constructor
	Fixed(const Fixed& fixed); 					// copy constructor
	~Fixed(); 									// destructor
	Fixed&	operator= (const Fixed& fixed); 	// copy assignment operator
	int		getRawBits(void) const; 			// returns the raw value of the fixed-point value.
	void	setRawBits(int const raw);			// Sets the raw value of the fixed-pointer number.

	// ex01
	Fixed(const int val);						// constructor
	Fixed(const float val);						// constructor
	float	toFloat(void)	const;				// converts the fixed-point value to a floating-point value
	int		toInt(void)		const;				// converts the fixed-point value to an integer value
};

// ex01 : Fixed class operator overloading
std::ostream&	operator<< (std::ostream& out, const Fixed& fixed);

#endif // FIXED_HPP
