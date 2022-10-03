#pragma once
#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"


class Point {

private:
// NOTE:  const variable initialization
// must be done before Object Instantiation
// (1) use Initializer List
// (2) set-init value directly in HPP
	const Fixed _x;
	const Fixed _y;

public:
	// mandatory
	Point();
	~Point();
	Point(const float x, const float y);
	Point(const Point& point);
	Point& operator= (const Point& point);

	// additional
	Point(const Fixed& x, const Fixed& y);
	Point operator- (const Point& point) const;
	Point operator+ (const Point& point) const;

	const Fixed getX() const;
	const Fixed getY() const;





};

bool bsp(Point const a, Point const b, Point const c, Point const point);


#endif // POINT_HPP
