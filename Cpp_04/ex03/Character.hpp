#pragma once
#include "ICharacter.hpp"

class Character : public ICharacter	
{
	public:
		Character(const std::string & name = "default");
		Character(const Character & src);
		~Character(void);
		Character & operator=(const Character & rhs);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
	protected:
	private:
		std::string _name;
		AMateria* _inventory[4];
};
