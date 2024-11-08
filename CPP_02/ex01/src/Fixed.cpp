// #include "Fixed.hpp"
#include "../Includes/Fixed.hpp"

const int Fixed::_fractional_bits = 8;

// Orthodox Canonical Form (Design) - Begin
//Default Constructor
Fixed::Fixed() : _fix_point_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

//Constructor with const int as param
Fixed::Fixed(const int input)
{
	std::cout << "Int constructor called" << std::endl;
	_fix_point_value = input << _fractional_bits;
}

Fixed::Fixed(const float input)
{
	std::cout << "Float constructor called" << std::endl;
	_fix_point_value = static_cast<int>(roundf(input * (1 << _fractional_bits)));
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
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
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

std::ostream	&operator<<(std::ostream& os, const Fixed &num)
{
	os << num.toFloat();
	return (os);
}
//Methodes Implementation - End
