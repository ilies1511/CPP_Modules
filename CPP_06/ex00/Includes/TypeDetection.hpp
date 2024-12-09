#pragma once

//Includes
#include <iostream>
#include <string>
#include <regex>

bool	isPseudoLiteral(const std::string& literal);
bool	isChar(const std::string& literal);
bool	isInt(const std::string& literal);
bool	isFloat(const std::string& literal);
bool	isDouble(const std::string& literal);
