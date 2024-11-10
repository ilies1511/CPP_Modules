#include "ClapTrap.hpp"

//Default Contructor
ClapTrap::ClapTrap() : _name("Zizou"), _HitPoint(10), _EnergyPoint(10), _AttackDamage(0)
{
	std::cout << "Default Constructor called\n";
}

//Default Name Contructor
ClapTrap::ClapTrap(std::string InputName) : _name(InputName), _HitPoint(10), _EnergyPoint(10), _AttackDamage(0)
{
	std::cout << "DefaultName Constructor called\n";
}

//Copy Costructor
ClapTrap::ClapTrap(const ClapTrap &og)
{
	std::cout << "Copy Constructor called\n";
	*this = og;
}

//Copy Assigment Operator
ClapTrap &ClapTrap::operator=(const ClapTrap& og)
{
	std::cout << "Copy assigment Constructor called\n";
	if (this != &og)
	{
		this->_name = og._name;
		this->_HitPoint = og._HitPoint;
		this->_EnergyPoint = og._EnergyPoint;
		this->_AttackDamage = og._AttackDamage;
	}
	else
		std::cout << coloring("[ERROR]: trying to assign the same value\n", RED);
	return (*this);
}

//Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called\n";
}

//Memebers
void ClapTrap::attack(const std::string& target)
{
	if (this->_HitPoint > 0 && this->_EnergyPoint > 0)
	{
		std::cout << this->_name << " used attack on " << target << " !\n";
		this->_EnergyPoint--;
	}
	else if (this->_HitPoint == 0)
		std::cout << this->_name << " lacks Hit Points to attack\n";
	else if (this->_EnergyPoint == 0)
		std::cout << this->_name << " lacks Energy Points to attack\n";
}
