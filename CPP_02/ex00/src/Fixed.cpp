#include "Fixed.hpp"

//Default Constructor
FixPointNbr::FixPointNbr() : _fix_point_value(0){}

//Copy Constructor
FixPointNbr::FixPointNbr(const FixPointNbr& og) : _fix_point_value(og._fix_point_value){}

//Copy assignment operator
FixPointNbr &FixPointNbr::operator=(const FixPointNbr& og)
{
	if (this != &og)
	{
		_fix_point_value = og._fix_point_value;
	}
	return (*this);
}

//Destructor
FixPointNbr::~FixPointNbr(){};
