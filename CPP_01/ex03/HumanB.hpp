#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

//Includes
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string	name;
		Weapon		*weaponB;
	public:
	HumanB(std::string Name);
	~HumanB(){};
	void	attack();
	void	setWeapon(Weapon &obj);
};

#endif
