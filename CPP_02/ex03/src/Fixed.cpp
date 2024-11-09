/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 23:39:14 by iziane            #+#    #+#             */
/*   Updated: 2024/11/09 23:39:18 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Fixed.hpp"
#include "../Includes/Fixed.hpp"

const int Fixed::_fractional_bits = 8;
const int Fixed:: _epsilon = 1;

// Orthodox Canonical Form (Design) - Begin
//Default Constructor
Fixed::Fixed() : _fix_point_value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

//Constructor with const int as param
Fixed::Fixed(const int input)
{
	// std::cout << "Int constructor called" << std::endl;
	_fix_point_value = input << _fractional_bits;
}

Fixed::Fixed(const float input)
{
	// std::cout << "Float constructor called" << std::endl;
	_fix_point_value = static_cast<int>(roundf(input * (1 << _fractional_bits)));
}

//Copy Constructor
Fixed::Fixed(const Fixed& og) : _fix_point_value(og._fix_point_value)
{
	// std::cout << "Copy constructor called" << std::endl;
}

//Copy assignment operator
Fixed &Fixed::operator=(const Fixed& og)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &og)
	{
		_fix_point_value = og._fix_point_value;
	}
	return (*this);
}

//Destructor
Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}
// Orthodox Canonical Form (Design) - End

//Methodes Implementation - Begin
int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (_fix_point_value);
}

void Fixed::setRawBits( int const raw )
{
	_fix_point_value = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(_fix_point_value) / (1 << _fractional_bits));
}

int Fixed::toInt(void) const
{
	return (_fix_point_value >> _fractional_bits);
}

// Overload FNC-Begin
std::ostream	&operator<<(std::ostream& os, const Fixed &num)
{
	os << num.toFloat();
	return (os);
}

bool	Fixed::operator>(const Fixed &input)
{
	return (this->_fix_point_value > input.getRawBits()); //If true --> return (true)
}

bool	Fixed::operator<(const Fixed &input)
{
	return (this->_fix_point_value < input.getRawBits());
}

bool	Fixed::operator>=(const Fixed &input)
{
	return (this->_fix_point_value >= input.getRawBits());
}

bool	Fixed::operator<=(const Fixed &input)
{
	return (this->_fix_point_value <= input.getRawBits());
}

bool	Fixed::operator==(const Fixed &input)
{
	return (this->_fix_point_value == input.getRawBits());
}

bool	Fixed::operator!=(const Fixed &input)
{
	return (this->_fix_point_value != input.getRawBits());
}

//Arithmetic Operators
Fixed	Fixed::operator+(const Fixed &input) const
{
	Fixed	res;

	res.setRawBits(this->_fix_point_value + input.getRawBits());
	return (res);
}

Fixed	Fixed::operator-(const Fixed &input) const
{
	Fixed	res;

	res.setRawBits(this->_fix_point_value - input.getRawBits());
	return (res);
}

Fixed	Fixed::operator*(const Fixed &input) const
{
	Fixed	res;

	res.setRawBits(static_cast<int>((int64_t)this->_fix_point_value * input.getRawBits()) >> _fractional_bits);
	return (res);
}

Fixed	Fixed::operator/(const Fixed &input) const
{
	Fixed	res;

	res.setRawBits(static_cast<int>((int64_t)(this->_fix_point_value) << _fractional_bits) / input.getRawBits());
	return (res);
}

//Pre de/in-crement
Fixed	&Fixed::operator++()
{
	this->_fix_point_value += _epsilon;
	return (*this);
}

Fixed	&Fixed::operator--()
{
	this->_fix_point_value -= _epsilon;
	return (*this);
}

//Post de/in-crement
Fixed	Fixed::operator++(int)
{
	Fixed	stash = *this;

	this->_fix_point_value+= _epsilon;
	return (stash);
}

Fixed	Fixed::operator--(int)
{
	Fixed	stash = *this;

	this->_fix_point_value -= _epsilon;
	return (stash);
}

Fixed	&Fixed::min(Fixed &input1, Fixed &input2)
{
	if (input1.getRawBits() < input2.getRawBits())
		return (input1);
	return (input2);
}

Fixed	&Fixed::max(Fixed &input1, Fixed &input2)
{
	if (input1.getRawBits() > input2.getRawBits())
		return (input1);
	return (input2);
}

const Fixed	&Fixed::min(const Fixed &input1, const Fixed &input2)
{
	if (input1.getRawBits() < input2.getRawBits())
		return (input1);
	return (input2);
}

const Fixed	&Fixed::max(const Fixed &input1, const Fixed &input2)
{
	if (input1.getRawBits() > input2.getRawBits())
		return (input1);
	return (input2);
}

//Methodes Implementation - End
