#include "Point.hpp"

Point::Point(void): x(0), y(0)
{
}

Point::Point(const Fixed x, const Fixed y): x(x), y(y)
{
}

Point::Point(const Point & src)
{
	*this = src;
}

Point::~Point(void)
{
}

Point & Point::operator=(const Point & rhs)
{
	if (this != &rhs)
	{
		Fixed *x_pointer = const_cast<Fixed *>(&this->x);
		Fixed *y_pointer = const_cast<Fixed *>(&this->y);
		*x_pointer = rhs.x;
		*y_pointer = rhs.y;
	}
	return (*this);
}

Fixed Point::getX(void) const
{
	return (this->x);
}

Fixed Point::getY(void) const
{
	return (this->y);
}
