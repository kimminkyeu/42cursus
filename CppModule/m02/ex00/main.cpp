/*  NOTE: The Orthodox Canonical Class Form
 * (1) Default constructor: used internally to initialize objects and data members when no other value is available.
 * (2) Copy constructor: used in the implementation of call-by-value parameters.
 * (3) Copy assignment operator: used to assign one value to another. (for Deep Copy)
 * (4) Destructor: Invoked when an object is deleted. */

/**
 * NOTE:  Fixed Point Numbers : https://www.youtube.com/watch?v=ZMsrZvBmQnU
 */


#include <iostream>
#include "Fixed.hpp"

int main(void) {

  Fixed a;
  Fixed b(a);
  Fixed c;

  c = b;

  std::cout << a.getRawBits() << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << c.getRawBits() << std::endl;

  return 0;
}
