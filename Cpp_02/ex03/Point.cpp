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
		this->x = rhs.x;
		this->y = rhs.y;
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
