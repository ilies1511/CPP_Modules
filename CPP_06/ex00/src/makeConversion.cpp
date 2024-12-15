/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makeConversion.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:46:01 by iziane            #+#    #+#             */
/*   Updated: 2024/12/15 14:46:03 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverte.hpp"

void handleFloat_Double(const std::string& literal)
{
	// std::cout << "In handleFloat_Double() \n";
	double value = convertToDouble(literal);
	// std::cout << value << "\n";
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
	/*
		'std::fixed << std::setprecision(1) ' forces to display
		one decimal place although 3 and 3.0 mathematically equivalent
	*/
	std::cout << "\nfloat: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f\n";
	std::cout << "double: " << std::fixed << std::setprecision(1) << value << "\n";
	return ;
}

void handleInt(const std::string& literal)
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
	return ;
}

void handleChar(const std::string& literal)
{
	char charValue = literal[0];
	std::cout << "char: '" << charValue << "'\n";
	std::cout << "int: " << static_cast<int>(charValue) << "\n";
	std::cout << "float: " << static_cast<float>(charValue) << ".0f\n";
	std::cout << "double: " << static_cast<double>(charValue) << ".0\n";
	return ;
}

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
