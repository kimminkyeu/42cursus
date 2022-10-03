
#include <iostream>
#include "Point.hpp"

int main( void ) {

  {
    bool result = bsp(Point(0, 0), Point(6, 0), Point(0, 6), Point(1.8f, 1.8f));
    // bool result = bsp(Point(0, 0), Point(6, 0), Point(0, 6), Point(2, 2));
    // bool result = bsp(Point(0, 0), Point(6, 0), Point(0, 6), Point(0, 6));
    // bool result = bsp(Point(0, 0), Point(6, 0), Point(0, 6), Point(3, 3));
    // bool result = bsp(Point(2, 1), Point(1, 9), Point(8, 8), Point(3, 5));
    if (result == true)
      std::cout << "Point is inside triangle\n";
    else
      std::cout << "Point is outside of triangle\n";
  }
  return (0);
}
