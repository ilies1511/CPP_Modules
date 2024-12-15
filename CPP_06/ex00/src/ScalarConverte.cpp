/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverte.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:46:04 by iziane            #+#    #+#             */
/*   Updated: 2024/12/15 14:46:05 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			handleChar(literal);
			return ;
		}
		if (isInt(literal))
		{
			handleInt(literal);
			return;
		}
		if (isFloat(literal) || isDouble(literal))
		{
			handleFloat_Double(literal);
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
