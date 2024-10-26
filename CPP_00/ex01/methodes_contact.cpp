/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methodes_contact.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 21:08:35 by iziane            #+#    #+#             */
/*   Updated: 2024/10/26 21:12:36 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

/*
	Methode-Definition of Contact Class
*/

void Contact::add_x(std::string input_str, Add type)
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

void Contact::get_x(Add type)
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

void Contact::get_all(void)
{
	const int label_width = 20;
	std::cout << std::left;
	std::cout << std:: setw(label_width) << "First Name: "<< first_name << '\n';
	std::cout << std:: setw(label_width) << "Last Name: " << last_name << '\n';
	std::cout << std:: setw(label_width) << "Nickname: " << nickname << '\n';
	std::cout << std:: setw(label_width) << "Phone Number: " << phone_number << '\n';
	std::cout << std:: setw(label_width) << "Darkest Secret: " << darkest_secret << '\n';
}

std::string Contact::formatColumn(const std::string &text) const
{
	const int width = 10;
	if (text.length() > width)
		return (text.substr(0, width - 1) + ".");
	else
		return std::string(width - text.length(), ' ') + text;
}

void Contact::get_formated(std::size_t highest_index) const
{
	std::cout << formatColumn(std::to_string(highest_index + 1)) << "|";
	std::cout << formatColumn(first_name) << "|";
	std::cout << formatColumn(last_name) << "|";
	std::cout << formatColumn(nickname) << '\n';
}
