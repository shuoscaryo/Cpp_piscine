/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:50:04 by orudek            #+#    #+#             */
/*   Updated: 2023/11/04 18:39:50 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

int const Fixed::bits = 8;

Fixed::Fixed(void)
{
	value = 0;
}

Fixed::Fixed(const int value)
{
	this->value = value << bits;
}

Fixed::Fixed(const float value)
{
	int integer = roundf(value);
	int decimal_bits = roundf((value - integer)* (1 << bits));
	this->value = (integer << bits) + decimal_bits;
}

Fixed::Fixed(const Fixed & src)
{
	*this = src;
}

Fixed::~Fixed(void)
{
}

Fixed & Fixed::operator=(const Fixed & rhs)
{
	value = rhs.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (value);
}

void Fixed::setRawBits(int const raw)
{
	value = raw;
}

float Fixed::toFloat(void) const
{
	return ((value >> bits) + (float)(value & 0xff) / (1 << bits));
}

int Fixed::toInt(void) const
{
	return (value >> bits);
}

std::ostream & operator<<(std::ostream &os, Fixed const & fixed)
{
	if (fixed.getRawBits() & 0xff)
		os << fixed.toFloat();
	else
		os << fixed.toInt();
	return (os);
}

bool Fixed::operator >(Fixed const & rhs) const
{
	return (value > rhs.getRawBits());
}

bool Fixed::operator <(Fixed const & rhs) const
{
	return (value < rhs.getRawBits());
}

bool Fixed::operator >=(Fixed const & rhs) const
{
	return (value >= rhs.getRawBits());
}

bool Fixed::operator <=(Fixed const & rhs) const
{
	return (value <= rhs.getRawBits());
}

bool Fixed::operator ==(Fixed const & rhs) const
{
	return (value == rhs.getRawBits());
}

bool Fixed::operator !=(Fixed const & rhs) const
{
	return (value != rhs.getRawBits());
}

Fixed Fixed::operator +(Fixed const & rhs) const
{
	return (Fixed(toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator -(Fixed const & rhs) const
{
	return (Fixed(toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator *(Fixed const & rhs) const
{
	return (Fixed(toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator /(Fixed const & rhs) const
{
	return (Fixed(toFloat() / rhs.toFloat()));
}

Fixed& Fixed::operator++(void)
{
	value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed& Fixed::operator--(void)
{
	value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

Fixed & Fixed::min(Fixed & a, Fixed & b)
{
	return (a < b ? a : b);
}

Fixed const & Fixed::min(Fixed const & a, Fixed const & b)
{
	return (a < b ? a : b);
}

Fixed & Fixed::max(Fixed & a, Fixed & b)
{
	return (a > b ? a : b);
}

Fixed const & Fixed::max(Fixed const & a, Fixed const & b)
{
	return (a > b ? a : b);
}
