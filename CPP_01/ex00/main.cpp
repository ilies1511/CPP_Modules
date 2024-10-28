#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie new_zombie;

	new_zombie.set_name(name);
	new_zombie.announce();
}

void Zombie::set_name(const std::string &input_name)
{
	name = input_name;
	return ;
}

Zombie *newZombie(std::string name)
{
	Zombie *new_zombie;
	// Zombie *new_zombie = new Zombie;

	new_zombie = new Zombie;
	new_zombie->set_name(name);
	return (new_zombie);
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

int	main(void)
{
	Zombie *heapZombie;

	//Object on Heap
	heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	delete heapZombie;
	//Object on Stack
	randomChump("StackZombie");
	return (0);
}
