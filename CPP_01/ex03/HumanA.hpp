#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

//Includes
#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA
{
	private:
		std::string	name;
		Weapon		&weaponRE;
	public:
		// void	setWeaponTyp("alo ");
		HumanA(std::string Name, Weapon &obj);
		~HumanA(){};
		void	attack();
};

#endif
