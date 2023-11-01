#pragma once
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource & src);
		~MateriaSource(void);
		MateriaSource & operator=(const MateriaSource & rhs);
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
	protected:
	private:
		AMateria* _inventory[4];
};
