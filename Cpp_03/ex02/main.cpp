/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:06:01 by orudek            #+#    #+#             */
/*   Updated: 2023/10/30 19:16:26 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap fragTrap("FragTrap");

	fragTrap.attack("enemy");
	fragTrap.takeDamage(30);
	fragTrap.printEnergyPoints();
	fragTrap.printHitPoints();
	fragTrap.beRepaired(20);
	fragTrap.printEnergyPoints();
	fragTrap.printHitPoints();
	fragTrap.highFivesGuys();
	return (0);
}