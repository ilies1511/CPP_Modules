/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:46:57 by iziane            #+#    #+#             */
/*   Updated: 2024/11/21 09:46:58 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal(), _brain(new Brain())
{
	setType("Dog");
	std::cout << "[DOG]: Default Constructor called for " << getType() << "\n";
}

Dog::Dog(const Dog &og) : Animal(og), _brain(new Brain(*(og._brain)))
{
	*this = og;
	std::cout << "[DOG]: Copy Constructor called for " << getType() << "\n";
}


Dog &Dog::operator=(const Dog &og)
{
	std::cout << "[DOG]: Copy Assignment operator called for " << getType() << "\n";
	if (this != &og)
	{
		Animal::operator=(og);
		if (_brain)
			delete (_brain);
		_brain = new Brain(*og._brain);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "[DOG]: Destructor called for " << getType() << "\n";
	delete _brain;
}

Brain* Dog::getBrain() const
{
	return _brain;
}

void	Dog::makeSound() const
{
	std::cout << "[DOG]: " << getType() << " makes WUF WUF\n";
}


