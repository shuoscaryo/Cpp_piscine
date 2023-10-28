/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:49:56 by orudek            #+#    #+#             */
/*   Updated: 2023/10/27 16:44:23 by orudek           ###   ########.fr       */
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
	private:
		int value;
		static int const bits;
};

std::ostream & operator<<(std::ostream &os, Fixed const & fixed);