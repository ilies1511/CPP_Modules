/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 23:31:37 by iziane            #+#    #+#             */
/*   Updated: 2024/10/26 23:31:38 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

// void	print_log(Status status, const std::string &str)
// {
// 	Log			log;

// 	log.mf_set_level(status);
// 	log.mf_info(str);
// }

//
void	handle_exit(void)
{
	std:: system("clear");
	exit(1);
}

void	handle_search(PhoneBook *pb)
{
	std::system("clear");
	search_contact(pb);
	std::system("clear");
}

void	handle_add(PhoneBook *pb)
{
	std:: system("clear");
	add_contact(pb);
	std:: system("clear");
}

void generate_art(void)
{
	std::cout << "======================================" << std::endl;
	std::cout << "========== WELCOME TO MY PB! =========" << std::endl;
	std::cout << "======================================" << std::endl;
	std::cout << "=== THE ULTIMATE PHONEBOOK SYSTEM! ===" << std::endl;
	std::cout << "==== SAVE AND MANAGE CONTACTS! ====" << std::endl;
	std::cout << "=== KEEP YOUR TOP 8 CONTACTS CLOSE! ==" << std::endl;
	std::cout << "======================================" << std::endl;
	std::cout << std::endl;
}

void generate_phonebook()
{
	std::string	command;
	std::string	action;
	PhoneBook	pb;
	Log			log;

	generate_art();
	while (true)
	{
		std::cout << "Enter command: ";
		std::getline(std::cin, command);
		std::stringstream ss(command);
		ss >> action;
		if (action == "ADD" && !(ss >> action))
			handle_add(&pb);
		else if (action == "SEARCH")
			handle_search(&pb);
		else if (action == "EXIT" && !(ss >> action))
			handle_exit();
		else if (std::cin.eof())
		{
			std:: system("clear");
			exit(1);
		}
		else
			log.print_log(INFO, "Invalid command. Available Commands:\n\"ADD\", \"SEARCH\", \"REMOVE\" or \"EXIT\"!");
	}
}

int	main(void)
{
	std::system("clear");
	generate_phonebook();
	return (0);
}
