#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

//Includes
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

//Class
class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string mDT_name;
	//OCF
	public:
		DiamondTrap(void);
		DiamondTrap(std::string InputName);
		DiamondTrap(const DiamondTrap &og);
		DiamondTrap &operator=(const DiamondTrap &og);
		~DiamondTrap(void);
	public:
		void whoAmI();
};

#endif
