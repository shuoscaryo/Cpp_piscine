/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 23:42:46 by orudek            #+#    #+#             */
/*   Updated: 2023/10/30 00:09:36 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
int main()
{
	ClapTrap clap1("chiquitin");
	
	for (int i = 0; i < 10; i++) {
		clap1.attack("bad claptrap");
	}
	clap1.attack("bad claptrap");
	clap1.beRepaired(5);
	clap1.beRepaired(1);
	clap1.takeDamage(11);
	clap1.takeDamage(1);
	
	std::cout << "Poor chiquitin :(" << std::endl;
	ClapTrap clap2("grandullon");

	clap2.takeDamage(5);
	clap2.beRepaired(4);
	clap2.attack("another bad claptrap");
	clap2.beRepaired(2);
	
	return (1);
}