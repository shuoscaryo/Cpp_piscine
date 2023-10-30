/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:22:28 by orudek            #+#    #+#             */
/*   Updated: 2023/10/30 18:46:56 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap scavTrap("ruperto");

	scavTrap.attack("enemy");
	scavTrap.takeDamage(10);
	scavTrap.beRepaired(10);
	scavTrap.guardGate();
	return (0);
}