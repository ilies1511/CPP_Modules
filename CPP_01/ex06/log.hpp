// #pragma once <==> ersetzt '#ifndef, #define #endif'

#ifndef LOG_HPP
#define LOG_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

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

enum Status
{
	SUCCESS,
	ERROR,
	INFO
};

// Classes
class Log
{
private:
	// Methodes
	Status m_loglevel;

public:
	// void print_log(Status status, const std::string &str);
	void mf_set_level(Status level);
	void mf_error(const std::string &msg);
	void mf_info(const std::string &msg);
	void mf_success(const std::string &msg);
	// Constructor/Destructor
public:
	Log() {}
	~Log() {}
};

//FNC-Prototypes
void print_log(Status status, const std::string &str);

#endif
