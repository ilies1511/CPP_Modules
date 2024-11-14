/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:47:40 by iziane            #+#    #+#             */
/*   Updated: 2024/11/14 16:47:41 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//Default Contructor
ClapTrap::ClapTrap() : _name("Ayfon"), _HitPoint(10), _EnergyPoint(10), _AttackDamage(0)
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
		std::cout << this->_name << " attacks " << target << " causing " << this->_AttackDamage << " points of damage!\n";
		this->_EnergyPoint--;
	}
	else if (this->_HitPoint == 0)
		std::cout << this->_name << " lacks Hit Points to attack\n";
	else if (this->_EnergyPoint == 0)
		std::cout << this->_name << " lacks Energy Points to attack\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_HitPoint >= amount)
	{
		std::cout << this->_name << " has taken " << amount << " damage!\n";
		this->_HitPoint -= amount;
	}
	else
		std::cout << this->_name << " is dead\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_EnergyPoint > 0)
	{
		std::cout << "ClapTrap " << this->getName() << " repaired " << amount << "\n";
		this->_HitPoint += amount;
		this->_EnergyPoint--;
	}
	else
		std::cout << this->getName() << " has no Energy Points left to repair\n";
}

//getter

std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

size_t	ClapTrap::getHitPoint(void) const
{
	return (this->_HitPoint);
}

size_t	ClapTrap::getEnergyPoint(void) const
{
	return (this->_EnergyPoint);
}

size_t	ClapTrap::getAttackDamage(void) const
{
	return (this->_AttackDamage);
}

//setter
void	ClapTrap::setAttackDamage(size_t const damage)
{
	this->_AttackDamage = damage;
}

void	ClapTrap::setHitPoint(size_t const InputHitPoint)
{
	this->_HitPoint = InputHitPoint;
}

void	ClapTrap::setEnergyPoint(size_t const InputEnergyPoint)
{
	this->_EnergyPoint = InputEnergyPoint;
}

