#include "ScalarConverte.hpp"

//Exceptions--BEGIN
const char *ScalarConverte::NonDisplayableCharException::what() const throw()
{
	return ("Non displayable Character !");
}

const char *ScalarConverte::ImpossibleConversionException::what() const throw()
{
	return ("Impossible Conversion !");
}
//Exceptions--END

void	ScalarConverte::convert(const std::string& literal)
{
	(void)literal;
}


