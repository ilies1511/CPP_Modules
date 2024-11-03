#ifndef FIXED_HPP
#define FIXED_HPP

//Includes
#include <iostream>
#include <string>

//Class

class FixPointNbr
{
	private:
		int					fix_point_value;
		static const int	fractional_bits;
	public:
		//Default Constructor that initializes the fixed-point number value to 0
		FixPointNbr();
		//Copy Constructor
		FixPointNbr(const FixPointNbr& copy);
		//Copy assignment operator overload
		FixPointNbr &operator=(const FixPointNbr&);
		~FixPointNbr();

		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

// FNC-Prototype
// void	printer(void);
#endif
