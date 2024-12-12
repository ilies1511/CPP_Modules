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
	private:
	// OCF - Deaktiviert, da Instanzierung nicht erlaubt
	public:
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
