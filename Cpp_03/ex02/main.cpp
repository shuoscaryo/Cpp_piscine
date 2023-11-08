/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:06:01 by orudek            #+#    #+#             */
/*   Updated: 2023/11/08 14:19:29 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap fragTrap("FragTrap");

	fragTrap.attack("enemy");
	fragTrap.takeDamage(30);
	fragTrap.beRepaired(20);
	fragTrap.highFivesGuys();
	return (0);
}