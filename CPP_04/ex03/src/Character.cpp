/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:49:41 by iziane            #+#    #+#             */
/*   Updated: 2024/11/21 09:49:42 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "printer.hpp"
// #include "../Includes/Character.hpp"

// // Statische Member initialisierens
// AMateria** Character::_floor = nullptr;
// size_t Character::_floorSize = 0;
// size_t Character::_floorCapacity = 0;

//OCF
Character::Character(Floor* floor) : _characterName("DefaultCharacter"), _SharedFloor(floor)
{
	for (size_t i = 0; i < 4; ++i) inventory[i] = nullptr;
	// std::cout << "[CHARACTER]: Default Construcor called\n";
	printer::ocf_printer("Character", printer::OCF_TYPE::DC);
}

Character::Character(std::string InputName, Floor* floor)
	: _characterName(InputName), _SharedFloor(floor)
{
	for (size_t i = 0; i < 4; ++i) inventory[i] = nullptr;
	// std::cout << "[CHARACTER]: Default Name Construcor called\n";
	printer::ocf_printer("Character", printer::OCF_TYPE::DNC);

}

Character::Character(const Character &og)
	: _characterName(og._characterName), _SharedFloor(og._SharedFloor) //TODO: check if flor is correct
{
	// std::cout << "[CHARACTER]: Copy Construcor called\n";
	printer::ocf_printer("Character", printer::OCF_TYPE::CC);
	// for (size_t i = 0; i < 4; ++i)
	// 	inventory[i] = nullptr; //Muss man die vorherigen Inventory loeschen ?
	for (size_t i = 0; i < 4; ++i)
		inventory[i] = og.inventory[i] ? og.inventory[i]->clone() : nullptr;
	// inventory[i] = og.inventory[i];
	// *this = og; //TODO: check if needed
}

Character &Character::operator=(const Character &og)
{
	printer::ocf_printer("Character", printer::OCF_TYPE::CAC);
	if (this != &og)
	{
		for (size_t i = 0; i < 4; ++i)
		{
			if (inventory[i] && inventory[i] != og.inventory[i])
			{
				delete inventory[i];
				inventory[i] = nullptr;
			}
		}
		this->_characterName = og._characterName;
		this->_SharedFloor = og._SharedFloor;
		for (size_t i = 0; i < 4; ++i)
		{
			if (og.inventory[i])
				inventory[i] = og.inventory[i]->clone();
			else
				inventory[i] = nullptr;
		}
	}
	return (*this);
}

// Character &Character::operator=(const Character &og)
// {
// 	// std::cout << "[CHARACTER]: Copy Assignment Construcor called\n";
// 	printer::ocf_printer("Character", printer::OCF_TYPE::CAC);
// 	if (this != &og)
// 	{
// 		this->_characterName = og._characterName;
// 		this->_SharedFloor = og._SharedFloor;
// 		for (size_t i = 0; i < 4; ++i)
// 			inventory[i] = og.inventory[i] ? og.inventory[i]->clone() : nullptr; //DeepKopie
// 		// inventory[i] = og.inventory[i]; --> kein DeepKopie
// 	}
// 	return (*this);
// }

Character::~Character()
{
	printer::ocf_printer("Character", printer::OCF_TYPE::D);
	// std::cout << "[CHARACTER]: Destrucor called\n";
	for (size_t i = 0; i < 4; ++i)
	{
		if (inventory[i])
			delete inventory[i];
	}
}

//Methodes
std::string const & Character::getName() const
{
	return (this->_characterName);
}

void Character::equip(AMateria* m)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			// std::cout << GREEN << "Material succefully equiped at slot " << i << "\n" << NC;
			printer::PrintMessage("[equip]: Material succefully equiped at slot " + std::to_string(i) ,printer::MessageType::SUCCESS);
			return ;
		}
	}
	printer::PrintMessage("[equip]: Material cannot be equipped: Inventory is FULL ", printer::MessageType::ERROR);
	if (m)
		this->_SharedFloor->addMateria(m);
}

void Character::unequip(int idx)
{
	if ((idx >= 0 && idx < 4) && inventory[idx])
	{
		std::cout << PURPLE << "Inventory at slot " << idx << " succesfully unequiped\n" << NC;
		this->_SharedFloor->addMateria(inventory[idx]);
		this->inventory[idx] = nullptr;
		return ;
	}
	printer::PrintMessage("[unequip]: No Inventory at slot " + std::to_string(idx) ,printer::MessageType::ERROR);
}

void Character::use(int idx, ICharacter& target)
{
	if ((idx >= 0 && idx < 4) && inventory[idx])
	{
		this->inventory[idx]->use(target);
		// std::cout << this->getName() << " use " << this->inventory[idx]->getType() << " at " << target.getName() << "\n";
		// std::cout << this->getName() << " attacks " << target.getName() << " with " << this->inventory[idx]->getType() << "\n";
	}
}



// //Floor
// void Character::resizeFloor(size_t newCapacity)
// {
// 	// Speicher für neues Floor-Array reservieren
// 	AMateria** newFloor = new AMateria*[newCapacity];
// 	// Alte Daten kopieren
// 	for (size_t i = 0; i < _floorSize; ++i)
// 		newFloor[i] = _floor[i];
// 	// Alten Speicher freigeben
// 	delete[] _floor;
// 	// Neues Array verwenden
// 	_floor = newFloor;
// 	_floorCapacity = newCapacity;
// }
