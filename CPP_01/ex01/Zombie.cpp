#include "Zombie.hpp"

void Zombie::set_name(const std::string &input_name)
{
	name = input_name;
	return ;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
