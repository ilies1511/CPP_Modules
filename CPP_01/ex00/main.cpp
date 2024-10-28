#include "Zombie.hpp"

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
