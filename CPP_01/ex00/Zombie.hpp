#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

//Includes
# include <iostream>
# include <string>


// ANSI Escape Codes
const std::string GREEN = "\033[0;32m";
const std::string RED = "\033[0;31m";
const std::string BLUE = "\033[0;34m";
const std::string BOLD = "\033[1m";
const std::string NC = "\033[0m"; // Zurücksetzen

/*
	Usage:
		std::cout << coloring("Dieser Text ist grün!", GREEN) << std::endl;
*/
inline std::string coloring(const std::string text, const std::string &color)
{
	return (color + text + NC);
}

class Zombie
{
	private:
		std::string name;
	public:
		void announce(void);
}

#endif
