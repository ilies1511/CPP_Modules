#ifndef POINT_HPP
#define POINT_HPP

//Includes
#include "Fixed.hpp"

// ANSI Escape Codes
const std::string GREEN = "\033[0;32m";
const std::string RED = "\033[0;31m";
const std::string BLUE = "\033[0;34m";
const std::string BOLD = "\033[1m";
const std::string ORANGE = "\033[38;2;255;165;0m";
const std::string PURPLE = "\033[38;2;128;0;128m";
const std::string NC = "\033[0m"; // Zurücksetzen

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
		/*
			Da Point nur const-Mitglieder enthält, ist die Klasse im
			Wesentlichen unveränderlich (immutable), was bedeutet,
			dass ein Zuweisungsoperator nicht benötigt
		*/
		Point &operator=(Point& og);
		//Destructor
		~Point();
	//Members:
		const Fixed& getX() const;
		const Fixed& getY() const;
};

//FNC-Prototypes
bool bsp( Point const a, Point const b, Point const c, Point const point);
/*
	Usage:
		std::cout << coloring("Dieser Text ist grün!", GREEN) << std::endl;
*/
std::string coloring(const std::string text, const std::string &color);

#endif
