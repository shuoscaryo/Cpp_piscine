#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string const &name) :
	ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << _name << " is born!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap & src) :
	ClapTrap(src._name + "_clap_name"), ScavTrap(src._name + "_clap_name"), FragTrap(src._name + "_clap_name")
{
	std::cout << "DiamondTrap " << _name << " is born!" << std::endl;
	*this = src;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap & DiamondTrap::operator=(const DiamondTrap & rhs)
{
	if (this != &rhs)
	{
		this->ClapTrap::_name = rhs._name + "_clap_name";
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

void DiamondTrap::whoAmI(void) const
{
	std::cout << "DiamondTrap name: " << this->_name << std::endl;
	std::cout << "ClapTrap name: " << this->ClapTrap::_name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}