#include "Zombie.hpp"

/*
	free in C++:
	- 'delete': free single Object
		calls only destructor of THAT object and frees it
	- 'delete[]': use to free hole array
		calls destructor for every single element of the array and frees hole arr.
*/
int	main(void)
{
	int		N;
	Zombie	*rethorde;

	N = 15;
	rethorde = zombieHorde(N, "zizou");
	if (rethorde == nullptr)
	{
		std::cerr << coloring("[ERRRO]: Failed to create zombie horde!", RED);
		return (1);
	}
	for (int i = 0; i < N; i++)
	{
		rethorde[i].announce();
	}
	delete[] rethorde;
	return (0);
}
