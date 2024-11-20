#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

//Includes
#include <iostream>
#include <limits>
#include <string>

// Forward-Deklaration von AMateria
class AMateria;
// konkrete Klasse Character, die dieses Interface implementiert.
class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};
#endif
