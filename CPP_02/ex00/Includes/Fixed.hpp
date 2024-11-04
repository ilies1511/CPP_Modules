#ifndef FIXED_HPP
#define FIXED_HPP

//Includes
#include <iostream>
#include <string>

//Class

class FixPointNbr
{
	private:
		int					_fix_point_value;
		static const int	_fractional_bits = 8;
	public:
		//Default Constructor that initializes the fixed-point number value to 0
		FixPointNbr();
		//Copy Constructor
		FixPointNbr(const FixPointNbr& og);
		//Copy assignment operator overload
		FixPointNbr &operator=(const FixPointNbr& og);
		~FixPointNbr();

		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

// FNC-Prototype
// void	printer(void);
#endif
