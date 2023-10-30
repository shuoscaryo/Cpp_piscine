/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:59:15 by orudek            #+#    #+#             */
/*   Updated: 2023/10/30 13:18:51 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	std::string name;
	Weapon& weapon;
public:
	HumanA(std::string const name, Weapon& weapon);
	void attack() const;
};
