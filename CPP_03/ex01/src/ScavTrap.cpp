#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(20);
	std::cout << "ScavTrap default constructor called\n";
}

explicit ScavTrap::ScavTrap(std::string InputName) : ClapTrap(InputName)
{
	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(20);
	std::cout << "ScavTrap named constructor called for " << InputName << "\n";
}

ScavTrap::ScavTrap(const ScavTrap &og) : ClapTrap(og)
{
	*this = og;
	std::cout << "ScavTrap copy constructor called\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &og)
{
	std::cout << "ScavTrap assignment operator called\n";
	if (this != &og)
	{
		ClapTrap::operator=(og);
		setHitPoint(og.getHitPoint());
		setEnergyPoint(og.getEnergyPoint());
		setAttackDamage(og.getAttackDamage());
	}
	return (*this);
}

// Destruktor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called\n";
}
