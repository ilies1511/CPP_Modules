/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 23:31:47 by iziane            #+#    #+#             */
/*   Updated: 2024/10/26 23:31:49 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

// Includes
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

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
	void mf_set_level(Status level);
	void mf_error(const std::string &msg);
	void mf_info(const std::string &msg);
	void print_log(Status status, const std::string &str);
	// Constructor/Destructor
public:
	Log() {}
	~Log() {}
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
	// Constructor
	Contact()
	{
		// std::cout << "Contact build\n";
	}
	// Destructor
	~Contact()
	{
		// std::cout << "Contact destroyed\n";
	}
	enum Add
	{
		FIRST_NAME,
		LAST_NAME,
		NICKNAME,
		PHONE_NBR,
		DARKEST_SECRET
	};
	// Helperfunction
	void add_x(std::string input_str, Add type);
	void get_x(Add type);
	void get_all(void);
	std::string formatColumn(const std::string &text) const;
	void get_formated(std::size_t highest_index) const;
};

class PhoneBook
{
private:
	Contact contacts[8];

public:
	PhoneBook()
	{
		amount_contacts = 0;
		manage_overflow = 0;
		// std::cout << "PhoneBook build\n";
	}
	// Destructor
	~PhoneBook()
	{
		// std::cout << "PhoneBook destroyed\n";
	}

public:
	size_t amount_contacts;
	static size_t manage_overflow;

	// Methodes:
	void add_contact_to_pb(Contact new_contact);
	void print_contact_data(Contact new_contact, std::size_t index);
	void print_table(std::size_t index);
	void display_contact_data(size_t index);
};
// FNC-Prototypes
void add_contact(PhoneBook *pb);
void search_contact(PhoneBook *pb);

#endif
