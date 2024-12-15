/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverte.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:45:38 by iziane            #+#    #+#             */
/*   Updated: 2024/12/15 15:47:43 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

//Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <regex>
#include <limits>
#include <exception>
#include "Extra/printer.hpp"
#include "Extra/Log.hpp"
#include "TypeDetection.hpp"
#include <sstream>

//Class
class ScalarConverte
{
	// OCF - Deaktiviert, da Instanzierung nicht erlaubt
	private:
		ScalarConverte(void) = delete;
		ScalarConverte(const ScalarConverte &og) = delete;
		ScalarConverte operator=(const ScalarConverte &og) = delete;
		~ScalarConverte(void) = delete;
	//Exceptions
	public:
		class NonDisplayableCharException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class ImpossibleConversionException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
//Memebers
	public:
		static void	convert(const std::string& literal);
};

//Loose Fnc
double	convertToDouble(const std::string& literal);
int		convertToInt(double value);
char	convertToChar(double value);

void	handlePseudoLiteral(const std::string& literal);
void	handleChar(const std::string& literal);
void	handleInt(const std::string& literal);
void	handleFloat_Double(const std::string& literal);

/*
 * The 'static' keyword in this context is used to define methods that are
 * independent of any specific instance of the class. These methods can be
 * called directly on the class itself, without needing to create an object
 * of the class.
 *
 * In the ScalarConverte class, the methods 'serialize' and 'deserialize'
 * are declared as 'static' because they provide functionality that is not
 * tied to a particular instance of the class. Instead, they operate on
 * input data (like pointers and raw values) and return results.
 *
 * This also ensures that:
 * - No instance of the ScalarConverte class can be created (as the constructor
 *   is deleted).
 * - The methods are accessible via the class itself, without the need for
 *   instantiating an object.
 * - The methods can be accessed in a simple and clear way, using the class
 *   name followed by the method name (e.g., ScalarConverte::serialize(...)).
 *
 * Using static methods in this case helps organize code that performs specific,
 * class-wide operations without requiring an object, making the code more
 * efficient and clearly structured.
 */
