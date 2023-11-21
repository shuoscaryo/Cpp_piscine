/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:22:35 by orudek            #+#    #+#             */
/*   Updated: 2023/11/08 14:11:53 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << _name << " is born!" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap & src): ClapTrap(src._name)
{
	std::cout << "ScavTrap " << _name << " is born!" << std::endl;
	
	*this = src;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << _name << " has been destroyed." << std::endl;
}

ScavTrap & ScavTrap::operator=(const ScavTrap & rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		_hitPoints = rhs._hitPoints;
		_energyPoints = rhs._energyPoints;
		_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " has entered in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_energyPoints == 0)
		std::cout << "ScavTrap " << _name << " can't attack because is out of energy!" << std::endl;
	else if (_hitPoints == 0)
		std::cout << "ScavTrap " << _name << " can't attack because is dead!" << std::endl;
	else
	{
		std::cout << "ScavTrap " << _name << " attacks "
		<< target << ", causing " << _attackDamage
		<< " points of damage!" << std::endl;
		_energyPoints--;
	}
}
