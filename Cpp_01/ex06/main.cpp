/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:17:58 by orudek            #+#    #+#             */
/*   Updated: 2023/10/20 13:03:02 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int c, char **v)
{
	if (c != 2)
	{
		std::cout << "Incorrect number of parameteres" << std::endl;
		return (1);
	}
	Harl harl;
	
	harl.complain(v[1]);
	return (0);
}