#include "Fixed.hpp"

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
	std::cout << "getRawBits member function called\n";
	return (this->_value);
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called\n";
	this->_value = raw;
}
