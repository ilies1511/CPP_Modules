#include "ScalarConverte.hpp"

void	handlePseudoLiteral(const std::string& literal)
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	// Float-Format mit 'f' anhängen
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		std::cout << "float: " << literal << "f\n";
	else if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		std::cout << "float: " << literal << "\n";
	// Double-Format direkt ausgeben
	if (literal == "nanf")
		std::cout << "double: nan\n";
	else if (literal == "+inff")
		std::cout << "double: +inf\n";
	else if (literal == "-inff")
		std::cout << "double: -inf\n";
	else
		std::cout << "double: " << literal << "\n";
}
