/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:20:16 by orudek            #+#    #+#             */
/*   Updated: 2023/10/30 13:20:49 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string const name)
{
	this->name = name;
	this->weapon = NULL;
}

void HumanB::attack() const
{
	if (weapon != NULL)
		std::cout << name << " attacks with their " << *weapon << std::endl;
	else
		std::cout << name << " attacks with their mighty knuckles" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}