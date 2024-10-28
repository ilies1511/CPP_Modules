#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	Zombie *new_zombie;
	// Zombie *new_zombie = new Zombie;

	new_zombie = new Zombie;
	new_zombie->set_name(name);
	return (new_zombie);
}
