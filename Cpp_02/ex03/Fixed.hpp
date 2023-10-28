/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:49:56 by orudek            #+#    #+#             */
/*   Updated: 2023/10/28 23:47:31 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed (const int value);
		Fixed (const float value);
		Fixed(const Fixed & src);
		~Fixed(void);
		Fixed & operator=(const Fixed & rhs);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		bool operator >(Fixed const & rhs) const;
		bool operator <(Fixed const & rhs) const;
		bool operator >=(Fixed const & rhs) const;
		bool operator <=(Fixed const & rhs) const;
		bool operator ==(Fixed const & rhs) const;
		bool operator !=(Fixed const & rhs) const;
		Fixed operator +(Fixed const & rhs) const;
		Fixed operator -(Fixed const & rhs) const;
		Fixed operator *(Fixed const & rhs) const;
		Fixed operator /(Fixed const & rhs) const;
		Fixed & operator++(void);
		Fixed operator++(int);
		Fixed & operator--(void);
		Fixed operator--(int);
		static Fixed & min(Fixed & a, Fixed & b);
		static Fixed const & min(Fixed const & a, Fixed const & b);
		static Fixed & max(Fixed & a, Fixed & b);
		static Fixed const & max(Fixed const & a, Fixed const & b);
	private:
		int value;
		static int const bits;
};

std::ostream & operator<<(std::ostream &os, Fixed const & fixed);