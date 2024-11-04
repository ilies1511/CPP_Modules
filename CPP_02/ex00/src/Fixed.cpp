#include "Fixed.hpp"

// Orthodox Canonical Form (Design) - Begin
//Default Constructor
Fixed::Fixed() : _fix_point_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

//Copy Constructor
Fixed::Fixed(const Fixed& og) : _fix_point_value(og._fix_point_value)
{
	std::cout << "Copy constructor called" << std::endl;
}

//Copy assignment operator
Fixed &Fixed::operator=(const Fixed& og)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &og)
	{
		_fix_point_value = og._fix_point_value;
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
