/*
	// horde = new Zombie[N]; --> implecite type conversion (int -> size_t)
	C++-Casting-Operatoren (static_cast, dynamic_cast, const_cast, reinterpret_cast):
		C-TypeCast: horde = new Zombie[(size_t)N];, however not recommanded
		C++TypeCast: Zombie[static_cast<size_t>(N)];
*/

#include "Zombie.hpp"
Zombie* zombieHorde( int N, std::string name )
{
	Zombie *horde;

	if (N < 0)
	{
		std::cerr << coloring("[Error]: N cannot be negative!", RED) << std::endl;
		return nullptr;
	}
	horde = new Zombie[static_cast<size_t>(N)];
	for(int i = 0; i < N; i++)
	{
		horde[i].set_name(name);
	}
	return (horde);
}

