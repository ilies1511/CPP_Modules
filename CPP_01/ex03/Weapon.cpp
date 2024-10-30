#include "Weapon.hpp"

Weapon::Weapon(std::string Weapon) : type(Weapon){}

void Weapon::setType(const std::string& new_type)
{
	type = new_type;
}

const std::string& Weapon::getType()
{
	return (type);
}
