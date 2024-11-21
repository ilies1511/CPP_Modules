/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:45:34 by iziane            #+#    #+#             */
/*   Updated: 2024/11/21 09:45:35 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	setType("Dog");
	std::cout << "[DOG]: Default Constructor called for " << getType() << "\n";
}

Dog::Dog(const Dog &og) : Animal(og)
{
	*this = og;
	std::cout << "[DOG]: Copy Constructor called for " << getType() << "\n";
}


Dog &Dog::operator=(const Dog &og)
{
	std::cout << "[DOG]: Copy Assignment operator called for " << getType() << "\n";
	if (this != &og)
		this->_m_type = og._m_type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "[DOG]: Destructor called for " << getType() << "\n";
}

void	Dog::makeSound() const
{
	std::cout << "[DOG]: " << getType() << " makes WUF WUF\n";
}


