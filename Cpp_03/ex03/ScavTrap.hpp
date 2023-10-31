/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:22:30 by orudek            #+#    #+#             */
/*   Updated: 2023/10/31 10:39:02 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(std::string const &name = "default");
		ScavTrap(const ScavTrap & src);
		~ScavTrap(void);
		ScavTrap & operator=(const ScavTrap & rhs);
		void guardGate(void);
		void attack(const std::string& target);
	private:
};
