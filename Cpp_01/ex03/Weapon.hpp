/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:41:39 by orudek            #+#    #+#             */
/*   Updated: 2023/10/30 13:12:25 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Weapon
{
	std::string type;
public:
	Weapon(std::string const type);
	const std::string& getType() const;
	void setType(std::string const type);
};

std::ostream& operator<<(std::ostream& os, const Weapon& weapon);