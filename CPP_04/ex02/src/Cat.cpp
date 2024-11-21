/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:48:40 by iziane            #+#    #+#             */
/*   Updated: 2024/11/21 09:48:43 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Cat.hpp"
#include "../Includes/Cat.hpp"

Cat::Cat() : AAnimal(), _brain(new Brain())
{
	setType("Cat");
	std::cout << "[CAT]: Default Constructor called for " << getType() << "\n";
}

Cat::Cat(const Cat &og) : AAnimal(og), _brain(new Brain(*(og._brain)))
{
	*this = og;
	std::cout << "[CAT]: Copy Constructor called for " << getType() << "\n";
}

Cat &Cat::operator=(const Cat &og)
{
	std::cout << "[CAT]: Copy Assignment operator called for " << getType() << "\n";
	if (this != &og)
	{
		AAnimal::operator=(og);
		if(_brain)
			delete _brain;
		_brain = new Brain(*og._brain);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "[CAT]: Destructor called for " << getType() << "\n";
	delete _brain;
}

void	Cat::makeSound() const
{
	std::cout << "[CAT]: " << getType() << " makes MIAU MIAU\n";
}

Brain* Cat::getBrain() const
{
	return (_brain);
}
