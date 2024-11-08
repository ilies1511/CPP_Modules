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
#include <cmath>

//Class

class Fixed
{
	private:
		int					_fix_point_value;
		static const int	_fractional_bits;
	public:
		//Default Constructor that initializes the fixed-point number value to 0
		Fixed();
		//Copy Constructor
		Fixed(const Fixed& og);
		//Constructor with const int as param
		Fixed(const int input);
		//Constructor with const float as param
		Fixed(const float input);
		//Copy assignment operator overload
		Fixed &operator=(const Fixed& og);
		//Destructor
		~Fixed();
		//Member Function
		int getRawBits(void)const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		//Overload Operators
		bool	operator>(const Fixed &input);
		bool	operator<(const Fixed &input);
		bool	operator>=(const Fixed &input);
		bool	operator<=(const Fixed &input);
		bool	operator==(const Fixed &input);
		bool	operator!=(const Fixed &input);
		//arithmetic operators
		Fixed	operator+(const Fixed &input) const;
		Fixed	operator-(const Fixed &input) const;
		Fixed	operator*(const Fixed &input) const;
		Fixed	operator/(const Fixed &input) const;

};

// FNC-Prototype
std::ostream&	operator<<(std::ostream& os, const Fixed &num);

// void	printer(void);
#endif
