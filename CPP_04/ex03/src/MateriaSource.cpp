/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:50:03 by iziane            #+#    #+#             */
/*   Updated: 2024/11/21 09:50:06 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../Includes/MateriaSource.hpp"
#include "MateriaSource.hpp"
#include "printer.hpp"

MateriaSource::MateriaSource(void)
{
	std::cout << "[MATERIASOURCE]: Default Construcor called\n";
	for (size_t i = 0; i < 4; i++)
		this->_MateriaSource_inventory[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource &og)
{
	std::cout << "[MATERIASOURCE]: Copy Construcor called\n";
	for (size_t i = 0; i < 4; i++)
	{
		// this->_MateriaSource_inventory[i] = nullptr;
		// this->_MateriaSource_inventory[i] = og._MateriaSource_inventory[i]->clone();
		this->_MateriaSource_inventory[i] = og._MateriaSource_inventory[i] \
			? og._MateriaSource_inventory[i]->clone() \
			: nullptr;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &og)
{
	std::cout << "[MATERIASOURCE]: Copy Assignment Construcor called\n";
	if (this != &og)
	{
		for (size_t i = 0; i < 4; ++i)
		{
			if (this->_MateriaSource_inventory[i] && this->_MateriaSource_inventory[i] != og._MateriaSource_inventory[i])
			{
				delete (this->_MateriaSource_inventory[i]);
				this->_MateriaSource_inventory[i] = nullptr;
			}
			if (og._MateriaSource_inventory[i])
				this->_MateriaSource_inventory[i] = og._MateriaSource_inventory[i]->clone();
			else
				this->_MateriaSource_inventory[i] = nullptr;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "[MATERIASOURCE]: Destrucor called\n";
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_MateriaSource_inventory[i])
			delete (this->_MateriaSource_inventory[i]);
	}
}

void MateriaSource::learnMateria(AMateria *og)
{
	if (og == nullptr)
		return ;
	for (size_t i = 0; i < 4; i++)
	{
		if ((this->_MateriaSource_inventory[i]) == nullptr)
		{
			this->_MateriaSource_inventory[i] = og; //TODO:Is this enough or do I have to make a Copy of AMAteria og and use this instead ?
			// this->_MateriaSource_inventory[i] = og->clone();
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_MateriaSource_inventory[i] \
			&& (this->_MateriaSource_inventory[i]->getType()) == type)
			return (this->_MateriaSource_inventory[i]->clone());
	}
	// std::cout << "[CREATEMATERIA]: ERROR, unknown type\nYOURS: " << type << "\t";
	printer::PrintMessage("[ERROR, createMateria]: unknown type\nYOURS:" + type + "\t", printer::MessageType::ERROR);
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_MateriaSource_inventory[i])
			// std::cout  << "KNOWN: " << this->_MateriaSource_inventory[i]->getType() << "\t";
			printer::PrintMessage("[ERROR, createMateria]: KNOWN: " + this->_MateriaSource_inventory[i]->getType() + "\t", printer::MessageType::ERROR);
	}
	return (nullptr);
}
