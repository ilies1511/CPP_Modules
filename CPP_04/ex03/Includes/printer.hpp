#ifndef PRINTER_HPP
# define PRINTER_HPP

#include <iostream>
#include <string>

// ANSI Escape Codes
const std::string GREEN = "\033[0;32m";
const std::string RED = "\033[0;31m";
const std::string BLUE = "\033[0;34m";
const std::string BOLD = "\033[1m";
const std::string ORANGE = "\033[38;2;255;165;0m";
const std::string PURPLE = "\033[38;2;128;0;128m";
const std::string NC = "\033[0m"; // Reset

// Prototyp der Coloring-Funktion
std::string coloring(const std::string& text, const std::string& color);

// Forward Declaration
class Floor;

namespace printer
{
	enum class MessageType { INFO, PROMPT, ERROR, HEADER };

	void PrintMessage(const std::string& message, MessageType type = MessageType::INFO);

	void Header(const std::string& Input);

	void print_Interactive(const std::string& Input);

	void print_invalidInput();

	void print_floor(Floor* sharedFloor);
}

#endif // PRINTER_HPP
