/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:03:30 by orudek            #+#    #+#             */
/*   Updated: 2023/11/04 18:41:50 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	
	std::cout << "\n======EXTRA TEST======\n";
	Fixed c = a;
	std::cout << Fixed::min(c, b) << std::endl; // 0.0078125
	std::cout << b / Fixed(2) << std::endl; // 5.05078
	std::cout << b + Fixed(-3.14f) << std::endl; // 6.96094
	std::cout << b - Fixed(18) << std::endl; // -7.89844
	std::cout << (c != a) << std::endl; // 0
	std::cout << (c == a) << std::endl; // 1
	return 0;
}