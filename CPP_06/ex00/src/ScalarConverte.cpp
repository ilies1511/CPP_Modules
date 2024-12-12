#include "ScalarConverte.hpp"

/*
	For those Helpers following principle applies:
	1. Input is double since it can hold every other dataType => no overflow
	2. Input is checked wether within Max & Min Value of DataType
	3. Return Value matches the destionation type (convertInt will return int)
*/


void ScalarConverte::convert(const std::string& literal)
{
	try
	{
		if (literal.empty())
			throw (ScalarConverte::ImpossibleConversionException());
		if (isChar(literal))
		{
			char charValue = literal[0];
			std::cout << "char: '" << charValue << "'\n";
			std::cout << "int: " << static_cast<int>(charValue) << "\n";
			std::cout << "float: " << static_cast<float>(charValue) << ".0f\n";
			std::cout << "double: " << static_cast<double>(charValue) << ".0\n";
			return ;
		}
		if (isInt(literal))
		{
			//TODO: MIN/MAX handling
			double value = std::stod(literal);
			std::cout << "char: ";
			try
			{
				char charValue = convertToChar(value);
				std::cout << "'" << charValue << "'";
			}
			catch (const std::exception& e)
			{
				std::cout << e.what();
			}
			std::cout << "\nint: " << static_cast<int>(value) << "\n";
			std::cout << "float: " << static_cast<float>(value) << ".0f\n";
			std::cout << "double: " << value << ".0\n";
			return;
		}

		if (isFloat(literal) || isDouble(literal))
		{
			// std::cout << "In float or double handling \n";
			double value = convertToDouble(literal);

			// Pseudo-Literal-Behandlung
			if (isPseudoLiteral(literal))
			{
				handlePseudoLiteral(literal);
				return ;
			}
			std::cout << "char: ";
			try
			{
				char charValue = convertToChar(value);
				std::cout << "'" << charValue << "'";
			}
			catch (const std::exception& e)
			{
				std::cout << e.what();
			}
			std::cout << "\nint: ";
			try
			{
				int intValue = convertToInt(value);
				std::cout << intValue;
			}
			catch (const std::exception& e)
			{
				std::cout << e.what();
			}
			std::cout << "\nfloat: " << static_cast<float>(value) << "f\n";
			std::cout << "double: " << value << "\n";
			return;
		}
		throw ScalarConverte::ImpossibleConversionException();
	}
	catch (const ScalarConverte::ImpossibleConversionException& e)
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
		return ;
	}
}

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
