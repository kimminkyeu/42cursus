#include "Fixed.hpp"
#include <ostream>

// EX00 ----------------------------------------------------------------
Fixed::Fixed()
	: _value(0)
{
	// std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& fixed)
{
	// std::cout << "Copy constructor called\n";

	/*  NOTE:  Output message might differ from Subject due to the implementation */
	// this->setRawBits(fixed.getRawBits()); 	// (1)
	*this = fixed;								// (2)
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called\n";
}

Fixed&	Fixed::operator= (const Fixed& fixed)
{
	// std::cout << "Copy assignment operator called\n";

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
	// std::cout << "Int constructor called\n";
	_value = val << _bits;
}

Fixed::Fixed(const float val)
	:_value(0)
{
	// std::cout << "Float Constructor called\n";
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


// ex02 -------------------------------------------------------------------
Fixed Fixed::operator+ (const Fixed& fixed) const
{
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator- (const Fixed& fixed) const
{
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator* (const Fixed& fixed) const
{
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/ (const Fixed& fixed) const
{
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

bool Fixed::operator> (const Fixed& fixed) const
{
	return (this->_value > fixed._value ? true : false);
}
bool Fixed::operator< (const Fixed& fixed) const
{
	return (this->_value < fixed._value ? true : false);
}
bool Fixed::operator>= (const Fixed& fixed) const
{
	return (this->_value >= fixed._value ? true : false);
}
bool Fixed::operator<= (const Fixed& fixed) const
{
	return (this->_value <= fixed._value ? true : false);
}
bool Fixed::operator== (const Fixed& fixed) const
{
	return (this->_value == fixed._value ? true : false);
}
bool Fixed::operator!= (const Fixed& fixed) const
{
	return (this->_value != fixed._value ? true : false);
}

Fixed Fixed::operator++ ()
{
	this->_value++;
	return (*this);
}
Fixed Fixed::operator++ (int)
{
	Fixed tmp = *this;
	this->_value++;
	return (tmp);
}
Fixed Fixed::operator-- ()
{
	this->_value--;
	return (*this);
}
Fixed Fixed::operator-- (int)
{
	Fixed tmp = *this;
	this->_value--;
	return (tmp);
}

// NOTE:  Don't add static keyword in cpp
Fixed& Fixed::min(Fixed &f1, Fixed &f2)
{
	return (f1 < f2 ? f1 : f2);
}

/* A static member function min that takes as parameters two references to constant
fixed-point numbers, and returns a reference to the smallest one. */
Fixed& Fixed::min(const Fixed &f1, const Fixed &f2)
{
	return (f1 < f2 ? const_cast<Fixed&>(f1) : const_cast<Fixed&>(f2));
}

Fixed& Fixed::max(Fixed &f1, Fixed &f2)
{
	return (f1 > f2 ? f1 : f2);
}

/* A static member function min that takes as parameters two references to constant
fixed-point numbers, and returns a reference to the greatest one. */
Fixed& Fixed::max(const Fixed &f1, const Fixed &f2)
{
	return (f1 > f2 ? const_cast<Fixed&>(f1) : const_cast<Fixed&>(f2));
}
