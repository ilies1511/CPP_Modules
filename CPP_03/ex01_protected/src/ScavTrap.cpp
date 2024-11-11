#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	// setHitPoint(100);
	// setEnergyPoint(50);
	// setAttackDamage(20);
	_HitPoint = 100;
	_EnergyPoint = 50;
	_AttackDamage = 20;
	std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(std::string InputName) : ClapTrap(InputName)
{
	// setHitPoint(100);
	// setEnergyPoint(50);
	// setAttackDamage(20);
	_HitPoint = 100;
	_EnergyPoint = 50;
	_AttackDamage = 20;
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
		// setHitPoint(og.getHitPoint());
		// setEnergyPoint(og.getEnergyPoint());
		// setAttackDamage(og.getAttackDamage());
		_HitPoint = og._HitPoint;
		_EnergyPoint = og._EnergyPoint;
		_AttackDamage = og._AttackDamage;

	}
	return (*this);
}

// Destruktor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called\n";
}

// Overwritten Methode
void ScavTrap::attack(const std::string& target)
{
	if (_HitPoint > 0 && this->_EnergyPoint > 0)
	{
		std::cout << "ScavTrap " << _name << " ferociously attacks " << target \
			<< " causing " << _AttackDamage << " points of damage!\n";
		_EnergyPoint--;
	}
	else
		std::cout << "ScavTrap " << _name << " lacks resources to attack\n";
}

// guardGate-Methode
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gatekeeper mode!\n";
}
