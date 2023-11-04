#pragma once
#include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice(void);
		Ice(const Ice & src);
		~Ice(void);
		Ice & operator=(const Ice & rhs);

		AMateria* clone(void) const;
		void use(ICharacter& target);
	protected:
	private:
};
