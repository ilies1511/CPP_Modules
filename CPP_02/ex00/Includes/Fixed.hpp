#ifndef FIXED_HPP
#define FIXED_HPP

/*
	Orthodox Canonical Form (OCF) in C++

	The Orthodox Canonical Form is a standard way to implement a class in C++,
	ensuring correct behavior for object creation, copying, assignment,
	and destruction.
	A class following the Orthodox Canonical Form includes four essential
	functions:

	1. Default Constructor:
		- Initializes an object without any arguments.
		- Provides a "safe" initial state, often setting member variables to
			default values.
	2.	Copy Constructor:
		- Called when a new object is created as a copy of an existing object.
		- Initializes the new object with the values of the original object.
		- Syntax: ClassName(const ClassName &other);
	3.	Copy Assignment Operator:
		- Called when an existing object is assigned the values of another
			existing object.
		- Checks for self-assignment (if (this != &other)) to prevent
			unnecessary operations.
		- Returns *this to allow chaining (e.g., a = b = c;).
		- Syntax: ClassName &operator=(const ClassName &other);
	4.	Destructor:
		- Called automatically when an object goes out of scope or is deleted.
		- Responsible for freeing resources held by the object (e.g., memory).
		- Syntax: ~ClassName();

	By including these four functions, the class follows C++ best practices,
		allowing it to
	behave predictably in various situations. This is especially important when
		dealing with dynamic memory or resources that require explicit cleanup.
*/

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
		//Destructor
		~FixPointNbr();

		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

// FNC-Prototype
// void	printer(void);
#endif
