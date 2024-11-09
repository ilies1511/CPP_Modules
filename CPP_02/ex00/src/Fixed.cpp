/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 23:38:17 by iziane            #+#    #+#             */
/*   Updated: 2024/11/09 23:38:18 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fractional_bits = 8;

// Orthodox Canonical Form (Design) - Begin
//Default Constructor
Fixed::Fixed() : _fix_point_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

//Copy Constructor

// Fixed::Fixed(const Fixed& og) : _fix_point_value(og._fix_point_value)
Fixed::Fixed(const Fixed& og) : _fix_point_value(og.getRawBits())
{
	std::cout << "Copy constructor called" << std::endl;
}

// //Copy Constructor, not efficient syntax
// Fixed::Fixed(const Fixed& og)
// {
// 	std::cout << "Copy constructor called" << std::endl;
// 	_fix_point_value = og._fix_point_value;
// }

//Copy assignment operator
Fixed &Fixed::operator=(const Fixed& og)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &og)
	{
		// _fix_point_value = og._fix_point_value;
		_fix_point_value = og.getRawBits();
	}
	return (*this);
}

//Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
// Orthodox Canonical Form (Design) - End

//Methodes Implementation - Begin
int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fix_point_value);
}

void Fixed::setRawBits( int const raw )
{
	_fix_point_value = raw;
}
//Methodes Implementation - End
