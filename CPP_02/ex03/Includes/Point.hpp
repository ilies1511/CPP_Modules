#ifndef POINT_HPP
#define POINT_HPP

//Includes
#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
		// const Fixed z;
	public:
		//Default Constructor that initializes the fixed-point number value to 0
		Point();
		//Constructor with param
		Point(const float input1, const float input2);
		//Copy Constructor
		Point(const Point &input);
		//Constructor with const float as param
		//Copy assignment operator overload
		Point &operator=(Point& og);
		//Destructor
		~Point();
};

//FNC-Prototypes
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
