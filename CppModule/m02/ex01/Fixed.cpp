#include <ostream>
#include "Fixed.hpp"

// EX00 ----------------------------------------------------------------
Fixed::Fixed()
	: _value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called\n";

	/*  NOTE:  Output message might differ from Subject due to the implementation */
	// this->setRawBits(fixed.getRawBits()); 	// (1)
	*this = fixed;								// (2)
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed&	Fixed::operator= (const Fixed& fixed)
{
	std::cout << "Copy assignment operator called\n";

	this->_value = fixed.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}

// EX01 ----------------------------------------------------------------
Fixed::Fixed(const int val)
	:_value(0)
{
	std::cout << "Int constructor called\n";
	_value = val << _bits;
}

Fixed::Fixed(const float val)
	:_value(0)
{
	std::cout << "Float Constructor called\n";
	this->_value = roundf(val * (1 << this->_bits));
}

float	Fixed::toFloat() const
{
	return (static_cast<float>(this->_value) / (1 << this->_bits));
}

int		Fixed::toInt() const
{
	return (this->_value >> this->_bits);
}

std::ostream&	operator<< (std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out); // for chaining
}
