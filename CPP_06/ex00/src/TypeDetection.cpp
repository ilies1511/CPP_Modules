#include "../Includes/TypeDetection.hpp"

/*
	The order of fnc Call for TypeDetection matters
	da z. B. ein char auch als ein gültiges int interpretiert werden könnte
*/
bool	isPseudoLiteral(const std::string& literal)
{
	if (!literal.compare("-inff") || !literal.compare("+inff") \
		|| !literal.compare("-inf") || !literal.compare("+inf") \
		|| !literal.compare("nan"))
		return (true);
	return (false);
}

bool	isChar(const std::string& literal)
{
	if (literal.length() == 1 && std::isprint(literal[0]) \
			&& !std::isdigit(literal[0]) && !isPseudoLiteral(literal))
		return (true);
	return (false);
}

bool	isInt(const std::string& literal)
{
	static const std::regex intRegex("^[+-]?\\d+$"); //static keyword more efficient since it doesnt get recompilled due to functioncall everytime
	if (std::regex_match(literal, intRegex)
		&& !isPseudoLiteral(literal))
		return (true);
	return (false);
}

bool	isFloat(const std::string& literal)
{
	static const std::regex floatRegex("^[+-]?\\d*\\.\\d+f$");
	// if (std::regex_match(literal, floatRegex))
	// 	return (true);
	// return (false);
	return (std::regex_match(literal, floatRegex));
}

bool	isDouble(const std::string& literal)
{
	static const std::regex doubleRegex("^[+-]?\\d*\\.\\d+$");

	return (std::regex_match(literal, doubleRegex));
}


