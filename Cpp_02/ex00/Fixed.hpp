/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:49:56 by orudek            #+#    #+#             */
/*   Updated: 2023/10/22 20:28:05 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed & src);
		~Fixed(void);
		Fixed & operator=(const Fixed & rhs);
		int getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int value;
		static int const bits;
};
