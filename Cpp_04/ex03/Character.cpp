#include "Character.hpp"

Character::Character(const std::string & name) :
	ICharacter(), _name(name)
{
	for ( int i = 0; i < 4; i++ )
		_inventory[i] = NULL;
}

Character::Character(const Character & src) :
	ICharacter()
{
	*this = src;
}

Character::~Character(void)
{
	for ( int i = 0; i < 4; i++ )
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

Character & Character::operator=(const Character & rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		for ( int i = 0; i < 4; i++ )
		{
			if (_inventory[i])
				delete _inventory[i];
			_inventory[i] = rhs._inventory[i];
		}
	}
	return (*this);
}

void Character::equip(AMateria* m)
{
	for ( int i = 0; i < 4; i++ )
	{
		if (_inventory[i] == m)
		{
			std::cout << "Cannot equip materia (already equipped)" << std::endl;
			return ;
		}
	}
	for ( int i = 0; i < 4; i++ )
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			return ;
		}
	}
	std::cout << "Cannot equip materia (inventory full)" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Cannot unequip materia (index out of range)" << std::endl;
		return ;
	}
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		std::cout << "Cannot use materia (index out of range)" << std::endl;
	else if (!_inventory[idx])
		std::cout << "Cannot use materia (empty slot)" << std::endl;
	else
		_inventory[idx]->use(target);
}

const std::string & Character::getName(void) const
{
	return (_name);
}