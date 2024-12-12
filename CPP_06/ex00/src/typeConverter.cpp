#include "ScalarConverte.hpp"

char convertToChar(double value)
{
	//Check if 'value' is in range of ascii and if its printable
	if (value < 0 || value > 127 || !std::isprint(static_cast<int>(value)))
		throw (ScalarConverte::NonDisplayableCharException());
	return (static_cast<char>(value));
}

int convertToInt(double value)
{
	if (value > std::numeric_limits<int>::max()
		|| value < std::numeric_limits<int>::min())
		throw (ScalarConverte::ImpossibleConversionException());
	return (static_cast<int>(value));
}

// static float convertToFloat(double value)
// {
// 	return (static_cast<float>(value));
// }

double convertToDouble(const std::string& literal)
{
	if (isPseudoLiteral(literal))
	{
		if (literal == "nan" || literal == "nanf")
			return (std::numeric_limits<double>::quiet_NaN());
		if (literal == "+inf" || literal == "+inff")
			return (std::numeric_limits<double>::infinity());
		if (literal == "-inf" || literal == "-inff")
			return (-std::numeric_limits<double>::infinity());
	}
	return (std::strtod(literal.c_str(), nullptr));
}
