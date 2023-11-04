#pragma once
#include <iostream>

class ICharacter;

class AMateria
{
	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(const AMateria&);

		virtual ~AMateria(void);

		AMateria& operator=(const AMateria&);

		std::string const & getType(void) const;

		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter& target);
	protected:
		std::string _type;
	private:
};
