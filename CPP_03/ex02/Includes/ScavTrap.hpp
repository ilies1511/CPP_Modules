#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

//Includes
# include "ClapTrap.hpp"
//Classes

class ScavTrap : public ClapTrap
{
	//OCF
	public:
		ScavTrap();
		explicit ScavTrap(std::string InputName);
		ScavTrap(const ScavTrap &og);
		ScavTrap& operator=(const ScavTrap &og);
		~ScavTrap();
	//Memebers
	public:
		void attack(const std::string& target) override; // override spezifiziert, dass wir die Methode überschreiben
		void guardGate(); // spezielle Methode für den Gatekeeper-Modus
};

#endif
