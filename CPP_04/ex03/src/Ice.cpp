/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:49:52 by iziane            #+#    #+#             */
/*   Updated: 2024/11/21 09:49:54 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "printer.hpp"

//OCF - Begin
Ice::Ice(void) : AMateria("ice") //TODO: check if correct
{
	// std::cout << "[ICE]: Default Constructor called\n";
	printer::ocf_printer("Ice", printer::OCF_TYPE::DC, LIGHT_CYAN);
}

Ice::Ice(const Ice &og) : AMateria(og)
{
	printer::ocf_printer("Ice", printer::OCF_TYPE::CC, LIGHT_CYAN);
	// std::cout << "[ICE]: Copy Constructor called\n";
	this->_type = og._type;
}

Ice& Ice::operator=(const Ice &og)
{
	printer::ocf_printer("Ice", printer::OCF_TYPE::CAC, LIGHT_CYAN);
	// std::cout << "[ICE]: Copy Assigment Constructor called\n";
	(void)og;
	return (*this);
}

Ice::~Ice()
{
	printer::ocf_printer("Ice", printer::OCF_TYPE::D, LIGHT_CYAN);
	// std::cout << "[ICE]: Destructor called\n";
}
//OCF - END

//Methodes
AMateria* Ice::clone() const
{
	return(new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
