/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:45:28 by iziane            #+#    #+#             */
/*   Updated: 2024/11/21 09:45:29 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//Default Constructor
Animal::Animal() : _m_type("Animal")
{
	std::cout << "[ANIMAL]: Default Constructor called for " << getType() << "\n";
	// std::cout << "[ANIMAL]: Default Constructor called\n";
}

//Default Name Constructor
Animal::Animal(std::string InputType) : _m_type(InputType)
{
	std::cout << "[ANIMAL]: NameDefault Constructor called for " << getType() << "\n";
	// std::cout << "[ANIMAL]: Default Constructor called for " << _m_type << "\n";
	// std::cout << "[ANIMAL]: NameDefault Constructor called\n";
}

//Copy Constructor
Animal::Animal(const Animal &og) : _m_type(og._m_type)
{
	std::cout << "[ANIMAL]: Copy Constructor called for " << getType() << "\n";
	*this = og;
}

//Copy Assigment Constructor
Animal &Animal::operator=(const Animal &og)
{
	std::cout << "[ANIMAL]: Copy Assignment operator called for " << getType() << "\n";
	if (this != &og)
		this->_m_type = og._m_type;
	return (*this);
}

//Destructor
Animal::~Animal()
{
	std::cout << "[ANIMAL]: Destructor called for " << getType() << "\n";
}

//Methodes
void	Animal::makeSound(void) const
{
	std::cout << "[ANIMAL]: " << getType() << " makes sound\n";
}

//Getter: Type
std::string	Animal::getType(void) const
{
	return (this->_m_type);
}

void	Animal::setType(std::string name)
{
	this->_m_type = name;
}

