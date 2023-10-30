#include "HumanA.hpp"

HumanA::HumanA(std::string const name, Weapon& weapon): weapon(weapon)
{
	this->name = name;
}

void HumanA::attack() const
{
	std::cout << name << " attacks with their " << weapon << std::endl;
}