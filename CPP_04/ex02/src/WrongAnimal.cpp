/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:48:54 by iziane            #+#    #+#             */
/*   Updated: 2024/11/21 09:48:55 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

//Default Constructor
WrongAnimal::WrongAnimal() : _m_type("WrongAnimal")
{
	std::cout << "[WRONGANIMAL]: Default Constructor called for " << getType() << "\n";
	// std::cout << "[WRONGANIMAL]: Default Constructor called\n";
}

//Default Name Constructor
WrongAnimal::WrongAnimal(std::string InputType) : _m_type(InputType)
{
	std::cout << "[WRONGANIMAL]: NameDefault Constructor called for " << getType() << "\n";
	// std::cout << "[WRONGANIMAL]: Default Constructor called for " << _m_type << "\n";
	// std::cout << "[WRONGANIMAL]: NameDefault Constructor called\n";
}

//Copy Constructor
WrongAnimal::WrongAnimal(const WrongAnimal &og) : _m_type(og._m_type)
{
	std::cout << "[WRONGANIMAL]: Copy Constructor called for " << getType() << "\n";
	*this = og;
}

//Copy Assigment Constructor
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &og)
{
	std::cout << "[WRONGANIMAL]: Copy Assignment operator called for " << getType() << "\n";
	if (this != &og)
		this->_m_type = og._m_type;
	return (*this);
}

//Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "[WRONGANIMAL]: Destructor called for " << getType() << "\n";
}

//Methodes
void	WrongAnimal::makeSound(void) const
{
	std::cout << "[WRONGANIMAL]: " << getType() << " makes sound\n";
}

//Getter: Type
std::string	WrongAnimal::getType(void) const
{
	return (this->_m_type);
}

void	WrongAnimal::setType(std::string name)
{
	this->_m_type = name;
}

