/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:01:50 by orudek            #+#    #+#             */
/*   Updated: 2023/10/30 13:20:41 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	std::string name;
	Weapon* weapon;
public:
	HumanB(std::string const name);
	void attack() const;
	void setWeapon(Weapon& weapon);
};
