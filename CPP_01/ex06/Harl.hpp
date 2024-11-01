#ifndef HARL_HPP
#define HARL_HPP

//Includes
#include <iostream>
#include <string>

// ANSI Escape Codes
const std::string GREEN = "\033[0;32m";
const std::string RED = "\033[0;31m";
const std::string BLUE = "\033[0;34m";
const std::string BOLD = "\033[1m";
const std::string ORANGE = "\033[38;2;255;165;0m";
const std::string PURPLE = "\033[38;2;128;0;128m";
const std::string NC = "\033[0m"; // Zurücksetzen

/*
	Usage:
		std::cout << coloring("Dieser Text ist grün!", GREEN) << std::endl;
*/
inline std::string coloring(const std::string text, const std::string &color)
{
	return (color + text + NC);
}

class Harl
{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
	public:
		Harl(){};
		~Harl(){};
		void complain( std::string level );
};

#endif
