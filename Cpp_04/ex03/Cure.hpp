#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(const Cure & src);
		~Cure(void);
		Cure & operator=(const Cure & rhs);

		AMateria* clone(void) const;
		void use(ICharacter& target);
	protected:
	private:
};
