#include "../Includes/Point.hpp"

Point::Point() : x(0), y(0){}

Point::Point(const float input1, const float input2) : x(input1), y(input2){};

Point::Point(const Point& og) : x(og.x), y(og.y){}

//Copy assignment operator overload
/*
	Da Point nur const-Mitglieder enthält, ist die Klasse im
	Wesentlichen unveränderlich (immutable), was bedeutet,
	dass ein Zuweisungsoperator nicht benötigt
*/
Point &Point::operator=(Point& og)
{
	if (this != &og)
		return (og);
	return (*this);
}

Point::~Point(){};

//Mebers

const Fixed& Point::getX() const
{
	return (x);
}

const Fixed& Point::getY() const
{
	return (y);
}

//Display
std::string coloring(const std::string text, const std::string &color)
{
	return (color + text + NC);
}
