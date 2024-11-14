/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:47:42 by iziane            #+#    #+#             */
/*   Updated: 2024/11/14 16:47:43 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Konstruktor mit Namen
// DiamondTrap::DiamondTrap(std::string InputName) : ClapTrap(InputName + "_clap_name"), ScavTrap(), FragTrap(), mDiamondTrap_name(InputName)
// {
// 	ScavTrap	tmp;

// 	std::cout << "DiamondTrap Name Constructor called for " << InputName << "\n";
// 	this->_HitPoint = FragTrap::_HitPoint;
// 	this->_AttackDamage = FragTrap::_AttackDamage;
// 	this->_EnergyPoint = tmp.getEnergyPoint();
// }

DiamondTrap::DiamondTrap(void)
	: ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(), mDiamondTrap_name("DefaultDiamondTrap")
{
	ScavTrap	tmp;

	std::cout << "DiamondTrap default constructor called\n";
	this->_HitPoint = FragTrap::_HitPoint;
	this->_AttackDamage = FragTrap::_AttackDamage;
	this->_EnergyPoint = tmp.getEnergyPoint();
}

DiamondTrap::DiamondTrap(std::string InputName)
	: ClapTrap(InputName + "_clap_name"), ScavTrap(), FragTrap(), mDiamondTrap_name(InputName)
{
	ScavTrap	tmp;

	std::cout << "DiamondTrap Name Constructor called for " << InputName << "\n";
	this->_HitPoint = FragTrap::_HitPoint;
	this->_AttackDamage = FragTrap::_AttackDamage;
	this->_EnergyPoint = tmp.getEnergyPoint();
}

//Copy Constructor
DiamondTrap::DiamondTrap(const DiamondTrap &og)
	: ClapTrap(og), ScavTrap(og), FragTrap(og), mDiamondTrap_name(og.mDiamondTrap_name)
{
	std::cout << "DiamondTrap copy constructor called\n";
}

//Copy Assignment Operator
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &og)
{
	std::cout << "DiamondTrap assignment operator called\n";
	if (this != &og)
	{
		ClapTrap::operator=(og);
		this->mDiamondTrap_name = og.mDiamondTrap_name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called\n";
}

//Memebers
void DiamondTrap::whoAmI()
{
	std::cout << "Name of the ClapTrap instance is: " << ClapTrap::_name << "\n";
	std::cout << "Name of the DiamondTrap instance is: " << this->mDiamondTrap_name << "\n";
}

// void	DiamondTrap::attack(const std::string& target)
// {
// 	ScavTrap::attack(target);
// }
