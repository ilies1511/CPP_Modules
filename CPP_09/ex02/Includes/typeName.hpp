#pragma once

//Includes
#include <string>

//Display Type of Container
// Spezialisierte Template-Funktion zur Rückgabe des Typnamens
template <typename T>
std::string typeName();

// Spezialisierung für std::vector<int>
template <>
inline std::string typeName<std::vector<int>>()
{
	return ("std::vector<int>");
}

// Spezialisierung für std::deque<int>
template <>
inline std::string typeName<std::deque<int>>()
{
	return ("std::deque<int>");
}

