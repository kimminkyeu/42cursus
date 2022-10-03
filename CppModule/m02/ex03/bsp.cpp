#include <assert.h>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	// NOTE:  [ Affine Combination ]
	// a + w1(vec1) + w2(vec2) = point
	// if w1 >= 0
	// if w2 >= 0
	// if (w1 + w2) <= 1
	// Then, point is inside triangle.

/****************************************************************
|	     a.x(c.x-a.x) + (p.y-a.y)(c.x-a.x) - p.x(c.y-a.y)		|
|   w1 =  ------------------------------------------------		|
|		    (b.y-a.y)(c.x-a.x) - (b.x-a.x)(c.y-a.y)				|
|																|
|																|
|	     p.y - a.y - w1(b.y - a.y)								|
|   w2 =  -------------------------								|
|		   	     c.y - a.y										|
*****************************************************************/

	std::cout << "point : " << point.getX() << "," << point.getY() << std::endl;

	Fixed s1 = c.getY() - a.getY();
	Fixed s2 = c.getX() - a.getX();
	Fixed s3 = b.getY() - a.getY();
	Fixed s4 = point.getY() - a.getY();

	Fixed w1 = (a.getX() * s1 + s4 * s2 - point.getX() * s1) / (s3 * s2 - (b.getX()-a.getX()) * s1);
	Fixed w2 = (s4- w1 * s3) / s1;
	std::cout << "w1    : " << w1 << std::endl;
	std::cout << "w2    : " << w2 << std::endl;
	// return (w1 >= 0 && w2 >= 0 && (w1 + w2) <= 1); --> is vertax or on edge.
	return (w1 > 0 && w2 > 0 && (w1 + w2) < 1);
}
