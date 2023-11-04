/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 23:07:45 by orudek            #+#    #+#             */
/*   Updated: 2023/11/04 18:19:52 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

static Fixed area(Point const a, Point const b, Point const c)
{
	Fixed Ax = a.getX();
	Fixed Ay = a.getY();
	Fixed Bx = b.getX();
	Fixed By = b.getY();
	Fixed Cx = c.getX();
	Fixed Cy = c.getY();

	Fixed area = Fixed(0.5f) * (Ax * (By - Cy) + Bx * (Cy - Ay) + Cx * (Ay - By));
	if (area < 0)
		area = area * -1;
	return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed A1 = area(a, b, point);
	Fixed A2 = area(a, c, point);
	Fixed A3 = area(b, c, point);
	Fixed A = area(a, b, c);
	
	/* std ::cout << "A1: " << ++A1 << std::endl;
	std ::cout << "A2: " << A2 << std::endl;
	std ::cout << "A3: " << A3 << std::endl;
	std ::cout << "A1 + A2 + A3 " << A1 + A2 + A3 << std::endl;
	std ::cout << "A: " << A << std::endl;
	std ::cout << "A1 + A2 + A3 - A: " << A1 + A2 + A3 - A << std::endl;
	std::cout << "error percentage: " << (A1 + A2 + A3- A) * 100 / A << std::endl; */
	Fixed ok_error(3); //admisible error for calculation in percentage
	return ( (A1 + A2 + A3 - A) * 100 < ok_error);
}