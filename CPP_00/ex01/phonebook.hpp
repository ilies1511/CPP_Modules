#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

// Includes
#include <iostream>
#include <string>
#include <sstream>

// ANSI Escape Codes
const std::string GREEN = "\033[0;32m";
const std::string RED = "\033[0;31m";
const std::string BLUE = "\033[0;34m";
const std::string BOLD = "\033[1m";
const std::string NC = "\033[0m";// Zurücksetzen

// FNC-Prototypes

/*
	Usage:
		std::cout << coloring("Dieser Text ist grün!", GREEN) << std::endl;
*/
std::string coloring(const std::string text, const std::string &color)
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
//Methodes
	Status	m_loglevel;
public:
	void	mf_set_level(Status level)
	{
		m_loglevel = level;
	}
	void	mf_error(const std::string &msg)
	{
		if (m_loglevel == ERROR)
			// std::cout << "[ERROR]: " << msg << '\n';
			std::cout << coloring("[ERROR]: " + msg, RED) << '\n';
	}
	void	mf_info(const std::string &msg)
	{
		if (m_loglevel == INFO)
			std::cout << coloring("[INFO]: " + msg, BLUE) << '\n';
	}
//Constructor/Destructor
public:
	Log(){}
	~Log(){}
};

class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
public:
	//Constructor
	Contact()
	{
		// std::cout << "Contact build\n";
	}
	//Destructor
	~Contact()
	{
		// std::cout << "Contact destroyed\n";
	}
};

class PhoneBook
{
private:
	Contact	contacts[8];
public:
//Methodes //TODO:
	//add_contact();
	//search_contacts();
	//remove_contact();
	//Constructor
	PhoneBook()
	{
		// std::cout << "PhoneBook build\n";
	}
	//Destructor
	~PhoneBook()
	{
		// std::cout << "PhoneBook destroyed\n";
	}
};

#endif
