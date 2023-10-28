#pragma once
#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(Fixed const x, Fixed const y);
		Point(const Point & src);
		~Point();
		Point & operator=(const Point & rhs);
		Fixed getX() const;
		Fixed getY() const;
	private:
		Fixed x;
		Fixed y;
};
