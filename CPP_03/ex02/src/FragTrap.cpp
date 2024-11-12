#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_HitPoint = 100;
	_EnergyPoint = 100;
	_AttackDamage = 30;
	std::cout << "TrapTrap default constructor called\n";
}

FragTrap::FragTrap(std::string InputName) : ClapTrap()
{
	_HitPoint = 100;
	_EnergyPoint = 100;
	_AttackDamage = 30;
	std::cout << "TrapTrap named constructor called for " << InputName << "\n";
}

FragTrap::FragTrap(const FragTrap &og) : ClapTrap(og)
{
	*this = og;
	std::cout << "FragTrap copy constructor called\n";
}

FragTrap &FragTrap::operator=(const FragTrap &og)
{
	std::cout << "FragTrap assignment operator called\n";
	if (this != &og)
	{
		FragTrap::operator=(og);
		_HitPoint = og._HitPoint;
		_EnergyPoint = og._EnergyPoint;
		_AttackDamage = og._AttackDamage;
	}
	return (*this);
}

// Destruktor
FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called\n";
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrag " << this->_name << " requests a high five!\n";
}
