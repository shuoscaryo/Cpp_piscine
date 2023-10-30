/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 23:42:49 by orudek            #+#    #+#             */
/*   Updated: 2023/10/30 19:07:50 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name):
	_name(name), _hitPoints(10),
	_energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " is born!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap & src)
{
	std::cout << "ClapTrap " << _name << " is born!" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << _name << " has been destroyed!" << std::endl;
}

ClapTrap & ClapTrap::operator=(const ClapTrap & rhs)
{
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (_energyPoints == 0)
		std::cout << "ClapTrap " << _name << " can't attack because is out of energy!" << std::endl;
	else if (_hitPoints == 0)
		std::cout << "ClapTrap " << _name << " can't attack because is dead!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " attacks "
		<< target << ", causing " << _attackDamage
		<< " points of damage!" << std::endl;
		_energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if ( _hitPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " takes "
		<< amount << " points of damage!" << std::endl;
		_hitPoints = amount > _hitPoints ? 0 : _hitPoints - amount;
		if (_hitPoints == 0)
			std::cout << "ClapTrap " << _name << " has died!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
		std::cout << "ClapTrap " << _name << " can't be repaired because is dead!" << std::endl;
	else if (_energyPoints == 0)
		std::cout << "ClapTrap " << _name << " can't be repaired because is out of energy!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " is repaired for "
		<< amount << " health points!" << std::endl;
		_hitPoints += amount;
		_energyPoints--;
	}
}

void ClapTrap::printEnergyPoints(void) const
{
	std::cout << "ClapTrap " << _name << " has " << _energyPoints << " energy points left!" << std::endl;
}

void ClapTrap::printHitPoints(void) const
{
	std::cout << "ClapTrap " << _name << " has " << _hitPoints << " hit points left!" << std::endl;
}