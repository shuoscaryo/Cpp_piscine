/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:07:24 by orudek            #+#    #+#             */
/*   Updated: 2023/10/19 22:17:46 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{}

Harl::~Harl()
{}

void Harl::debug(void)
{
	std::cout << "[DEBUG] I'm a debug message" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[INFO] I'm an info message" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[WARNING] I'm a warning message" << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ERROR] I'm an error message" << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++)
		if (level == levels[i])
			(this->*f[i])();
}