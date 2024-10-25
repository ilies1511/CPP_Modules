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
	void mf_set_level(Status level)
	{
		m_loglevel = level;
	}
	void mf_error(const std::string &msg)
	{
		if (m_loglevel == ERROR)
			// std::cout << "[ERROR]: " << msg << '\n';
			std::cout << coloring("[ERROR]: " + msg, RED) << '\n';
	}
	void mf_info(const std::string &msg)
	{
		if (m_loglevel == INFO)
			std::cout << coloring("[INFO]: " + msg, BLUE) << '\n';
	}
	void	print_log(Status status, const std::string &str)
	{
		// Log			log;

		mf_set_level(status);
		mf_info(str);
	}
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
	void add_x(std::string input_str, Add type)
	{
		if (type == FIRST_NAME)
			first_name = input_str;
		else if (type == LAST_NAME)
			last_name = input_str;
		else if (type == NICKNAME)
			nickname = input_str;
		else if (type == PHONE_NBR)
			phone_number = input_str;
		else if (type == DARKEST_SECRET)
			darkest_secret = input_str;
	}
	void get_x(Add type)
	{
		if (type == FIRST_NAME)
			std::cout << first_name << '\n';
		else if (type == LAST_NAME)
			std::cout << last_name << '\n';
		else if (type == NICKNAME)
			std::cout << nickname << '\n';
		else if (type == PHONE_NBR)
			std::cout << phone_number << '\n';
		else if (type == DARKEST_SECRET)
			std::cout << darkest_secret << '\n';
	}
	void get_all(void)
	{
		const int label_width = 20;

		std::cout << std::left;
		std::cout << std:: setw(label_width) << "First Name: "<< first_name << '\n';
		std::cout << std:: setw(label_width) << "Last Name: " << last_name << '\n';
		std::cout << std:: setw(label_width) << "Nickname: " << nickname << '\n';
		std::cout << std:: setw(label_width) << "Phone Number: " << phone_number << '\n';
		std::cout << std:: setw(label_width) << "Darkest Secret: " << darkest_secret << '\n';
	}

	// std::string	format_string(const std::string &str)
	// {
	// 	if (str.length() > 10)
	// 	{
	// 		str[9] = '.';
	// 		return (str);
	// 	}
	// 	else
	// 	{

	// 	}
	// }

	// Funktion zur Formatierung der Spalte mit Trunkierung und Rechtsausrichtung
	std::string formatColumn(const std::string &text) const
	{
		const int width = 10;
		if (text.length() > width)
			return (text.substr(0, width - 1) + ".");
		else
			return std::string(width - text.length(), ' ') + text;
	}
	// void get_sorted(std::size_t highest_index)
	// {
	// 	std::cout << highest_index + 1 << "|";
	// 	std::cout << first_name << "|";
	// 	std::cout << last_name << "|";
	// 	std::cout << nickname << '\n';
	// }
	void get_formated(std::size_t highest_index) const
	{
		std::cout << formatColumn(std::to_string(highest_index + 1)) << "|";
		std::cout << formatColumn(first_name) << "|";
		std::cout << formatColumn(last_name) << "|";
		std::cout << formatColumn(nickname) << '\n';
	}
};

class PhoneBook
	{
	private:
		Contact contacts[8];

	public:
		// Methodes //TODO:
		// add_contact();
		// search_contacts();
		// remove_contact();
		// Constructor
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

		void add_contact_to_pb(Contact new_contact, bool full)
		{
			if (full)
			{
				if (manage_overflow == 8)
					manage_overflow = 0;
				contacts[manage_overflow] = new_contact;
				manage_overflow++;
			}
			else
			{
				contacts[amount_contacts] = new_contact;
				amount_contacts++;
			}
			// std:: cout << coloring("Contact succesfully added\n", GREEN);
		}
		void print_contact_data(Contact new_contact, std::size_t index)
		{
			(void)new_contact;
			contacts[index].get_all();
		}

		void	print_table(std::size_t index)
		{
			contacts[index].get_formated(index);
		}

		void	display_contact_data(size_t index)
		{
			std::system("clear");
			contacts[index].get_all();
		}
	};
	// FNC-Prototypes
	void	add_contact(PhoneBook *pb);
	void	search_contact(PhoneBook *pb);

#endif
