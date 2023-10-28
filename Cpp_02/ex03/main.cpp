/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:19:09 by orudek            #+#    #+#             */
/*   Updated: 2023/10/28 23:40:18 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include "Point.hpp"
#include "Fixed.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

static bool cin_float(float &input)
{
	float aux;
	std::cin >> aux;
	if (std::cin.fail())
	{
		std::cout << "Invalid input." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return (false);
	}
	input = aux;
	return (true);
}

static Point ask_for_point(std::string name)
{
	float x;
	float y;
	
	do{
		std::cout << "Enter " << name << " [x y]: ";
		if (cin_float(x) && cin_float(y))
			break;
	} while (true);
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return (Point(Fixed(x), Fixed(y)));	
}

int main()
{
	Point a = ask_for_point("triangle first point");
	Point b = ask_for_point("triangle second point");
	Point c = ask_for_point("triangle third point");
	Point point = ask_for_point("point to check");
	
	if (bsp(a, b, c, point))
		std::cout << "The point is inside the triangle." << std::endl;
	else
		std::cout << "The point is outside the triangle." << std::endl;
	return (0);
}