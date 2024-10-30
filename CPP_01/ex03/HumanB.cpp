#include "HumanB.hpp"
void	HumanB::setWeapon(Weapon &obj)
{
	weaponB = &obj;
}

HumanB::HumanB(std::string Name) : name(Name), weaponB(nullptr){}

void	HumanB::attack(void)
{
	if (!weaponB)
		std::cout << name << " will go Bruce Lee Mode (no weapons)\n";
	else
		std::cout << name << " attacks with their " << weaponB->getType() << '\n';
}
