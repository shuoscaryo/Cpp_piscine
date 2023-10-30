/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:07:18 by orudek            #+#    #+#             */
/*   Updated: 2023/10/30 13:07:26 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *zombies = zombieHorde(5, "Zombie");
	for (int i = 0; i < 5; i++)
		zombies[i].announce();
	delete [] zombies;
	std::cout << std::endl;
	system("leaks -q zombieHorde");
	return (0);
}