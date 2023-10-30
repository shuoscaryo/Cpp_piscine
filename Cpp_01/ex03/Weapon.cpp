/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:43:57 by orudek            #+#    #+#             */
/*   Updated: 2023/10/30 13:12:20 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string const type)
{
	this->setType(type);
}

const std::string& Weapon::getType() const
{
	return (type);
}

void Weapon::setType(std::string const type)
{
	this->type = type;
}

std::ostream& operator<<(std::ostream& os, const Weapon& weapon)
{
	os << weapon.getType();
	return (os);
}