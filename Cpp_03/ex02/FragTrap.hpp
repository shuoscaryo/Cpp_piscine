/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:57:49 by orudek            #+#    #+#             */
/*   Updated: 2023/10/30 19:35:22 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(std::string const &name = "Default");
		FragTrap(const FragTrap & src);
		~FragTrap(void);
		FragTrap & operator=(const FragTrap & rhs);
		void highFivesGuys(void);
	private:
};
