#include "../Includes/Point.hpp"

Point::Point() : x(0), y(0){}

Point::Point(const float input1, const float input2) : x(input1), y(input2){};

Point::Point(const Point& og) : x(og.x), y(og.y){}

Point &Point::operator=(Point& og)
{
	if (this != &og)
		return (og);
	return (*this);
}

Point::~Point(){};




