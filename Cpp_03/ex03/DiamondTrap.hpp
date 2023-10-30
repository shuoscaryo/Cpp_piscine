#pragma once
#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(std::string const & name = "default");
		DiamondTrap(const DiamondTrap & src);
		~DiamondTrap(void);
		DiamondTrap & operator=(const DiamondTrap & rhs);
		void whoAmI(void) const;
	private:
		std::string _name;
};
