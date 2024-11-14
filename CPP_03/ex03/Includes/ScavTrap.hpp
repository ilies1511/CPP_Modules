/*
	The 'virtual' keyword in the context of inheritance allows for dynamic binding,
	enabling polymorphism. When a class is inherited virtually, like ScavTrap
	inheriting from ClapTrap, it ensures that only one instance of the base class
	(ClapTrap) is shared between derived classes (ScavTrap, FragTrap) in case
	of multiple inheritance. This prevents ambiguity and potential duplication of
	data members from ClapTrap, which could otherwise occur with non-virtual inheritance.

	In addition, the 'virtual' keyword applied to the destructor ensures that the
	correct destructor is called when deleting an object through a base class pointer,
	preventing resource leaks. When a derived class overrides a method (like 'attack'),
	the 'virtual' keyword ensures that the derived version is called at runtime,
	even when the object is referred to by a base class pointer or reference.
*/

#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

//Includes
# include "ClapTrap.hpp"
//Classes

class ScavTrap : virtual public ClapTrap
{
	//OCF
	public:
		ScavTrap();
		explicit ScavTrap(std::string InputName);
		ScavTrap(const ScavTrap &og);
		ScavTrap& operator=(const ScavTrap &og);
		virtual ~ScavTrap();
	//Memebers
	public:
		void attack(const std::string& target) override; // override spezifiziert, dass wir die Methode überschreiben
		void guardGate(); // spezielle Methode für den Gatekeeper-Modus
};

#endif
