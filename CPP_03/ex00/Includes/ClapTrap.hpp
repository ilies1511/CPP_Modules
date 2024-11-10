#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

//Includes
#include <iostream>
#include <string>

// ANSI Escape Codes
const std::string GREEN = "\033[0;32m";
const std::string RED = "\033[0;31m";
const std::string BLUE = "\033[0;34m";
const std::string BOLD = "\033[1m";
const std::string ORANGE = "\033[38;2;255;165;0m";
const std::string PURPLE = "\033[38;2;128;0;128m";
const std::string NC = "\033[0m"; // Zurücksetzen

//Class
class ClapTrap
{
	private:
		std::string _name;
		//represent the health of the ClapTrap
		size_t		_HitPoint;
		//attacking and repairing cost 1 energy point each
		size_t		_EnergyPoint;
		size_t		_AttackDamage;
	//Orthodox Canonical Form
	public:
		//Default Contructor
		ClapTrap();
		//Default Name Constructor
		ClapTrap(std::string InputName);
		//Copy Constructor
		ClapTrap(const ClapTrap &og);
		//Coopy Assignment operator
		ClapTrap& operator=(const ClapTrap& og);
		//Destructor
		~ClapTrap();
	//Members
	public:
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
	//getter/setter
	public:
		//setter
		void		setName(void);
		//getter
		std::string	getName(void) const;
		size_t		getHitPoint(void) const;
		size_t		getEnergyPoint(void) const;
		size_t		getAttackDamage(void) const;
};

//FNC-Prototyp
	/*
		Usage:
			std::cout << coloring("Dieser Text ist grün!", GREEN) << std::endl;
	*/
	std::string coloring(const std::string text, const std::string &color);
#endif
