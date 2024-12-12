#include "TypeDetection.hpp"

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

// // if (literal.size() > 0 && !isPseudoLiteral(literal))
// bool	isChar(const std::string& literal)
// {
// 	double	res;

// 	char *endptr = nullptr;
// 	res = std::strtod(literal.c_str(), &endptr);
// 	if (literal.c_str() == endptr)
// 	{
// 		if (literal.length() == 1
// 			&& !std::isdigit(literal[0]) && !isPseudoLiteral(literal))
// 			return (true);
// 	}
// 	else if (res >= 0 && res <=0)
// 	{
// 		return (true);
// 	}
// 	return (false);
// 	 // Regex: Prüft auf genau ein ASCII-Zeichen (sichtbar oder unsichtbar)
// 	std::regex charRegex(R"(^[\x00-\x7F]$)");
// 	// Prüfen, ob der String genau ein Zeichen lang ist und auf das Muster passt
// 	return (std::regex_match(literal, charRegex));
// }



bool isValidAsciiValue(const std::string& literal)
{
	std::regex asciiRegex(R"(^(12[0-7]|1[01][0-9]|[1-9]?[0-9])$)");
	return (std::regex_match(literal, asciiRegex));
}

bool isValidQuotedAlphabeticalChar(const std::string& literal)
{
	// std::regex charRegex(R"(^'[a-zA-Z]'$)");
	 std::regex charsOrStringRegex(R"(^('\0'|"\0"|\'[a-zA-Z]\')$)");
	if (literal == "\0")
		return (true);
	// return (std::regex_match(literal, charRegex));
	return (std::regex_match(literal, charsOrStringRegex));
}

bool isChar_OLD(const std::string& literal)
{
	if (literal.empty())// && literal != "\0")
		return (false);
	if (isValidAsciiValue(literal) || isValidQuotedAlphabeticalChar(literal))
		return (true);
	if (literal.length() == 1
		&& !std::isdigit(literal[0]) && !isPseudoLiteral(literal))
		return (true);
	return (false);
}

bool isChar(const std::string& literal)
{
	if (literal.length() == 1
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

	return (std::regex_match(literal, doubleRegex) || isPseudoLiteral(literal));
}


