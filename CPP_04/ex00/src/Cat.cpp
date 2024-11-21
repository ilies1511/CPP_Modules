/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:45:30 by iziane            #+#    #+#             */
/*   Updated: 2024/11/21 09:45:31 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	setType("Cat");
	std::cout << "[CAT]: Default Constructor called for " << getType() << "\n";
}

Cat::Cat(const Cat &og) : Animal(og)
{
	*this = og;
	std::cout << "[CAT]: Copy Constructor called for " << getType() << "\n";
}

Cat &Cat::operator=(const Cat &og)
{
	std::cout << "[CAT]: Copy Assignment operator called for " << getType() << "\n";
	if (this != &og)
		this->_m_type = og._m_type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "[CAT]: Destructor called for " << getType() << "\n";
}

void	Cat::makeSound() const
{
	std::cout << "[CAT]: " << getType() << " makes MIAU MIAU\n";
}
