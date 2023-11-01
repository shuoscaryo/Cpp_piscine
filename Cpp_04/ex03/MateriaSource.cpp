#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : IMateriaSource()
{
	for ( int i = 0; i < 4; i++ )
		_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource & src) : IMateriaSource()
{
	*this = src;
}

MateriaSource::~MateriaSource(void)
{
	for ( int i = 0; i < 4; i++ )
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

MateriaSource & MateriaSource::operator=(const MateriaSource & rhs)
{
	if (this != &rhs)
	{
		for ( int i = 0; i < 4; i++ )
		{
			if (_inventory[i])
				delete _inventory[i];
			_inventory[i] = rhs._inventory[i];
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
	for ( int i = 0; i < 4; i++ )
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			return ;
		}
	}
	std::cout << "Cannot learn materia (inventory full)" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for ( int i = 0; i < 4; i++ )
	{
		if (_inventory[i] && _inventory[i]->getType() == type)
			return (_inventory[i]->clone());
	}
	return (NULL);
}