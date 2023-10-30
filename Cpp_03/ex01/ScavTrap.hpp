/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:22:30 by orudek            #+#    #+#             */
/*   Updated: 2023/10/30 19:46:04 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(std::string const &name = "default");
		ScavTrap(const ScavTrap & src);
		~ScavTrap(void);
		ScavTrap & operator=(const ScavTrap & rhs);
		void guardGate(void);
	private:
};
