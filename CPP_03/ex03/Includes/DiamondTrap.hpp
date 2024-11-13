#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

//Includes
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

//Class
class DiamondTrap :  public ScavTrap, public FragTrap
{
	private:
		std::string mDiamondTrap_name; // own Name for DiamondTrap Instance
	//OCF
	public:
		DiamondTrap(void);
		DiamondTrap(std::string InputName);
		DiamondTrap(const DiamondTrap &og);
		DiamondTrap &operator=(const DiamondTrap &og);
		~DiamondTrap(void);
	public:
		void whoAmI();
		using ScavTrap::attack;
		// void	attack(const std::string& target);
};

#endif
