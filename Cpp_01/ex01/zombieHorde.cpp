/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:50:51 by orudek            #+#    #+#             */
/*   Updated: 2023/10/19 20:04:41 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *new_zombies = new Zombie[N];
	for (int i = 0; i < N; i++)
		new_zombies[i] = Zombie(name);
	return (new_zombies);
}
