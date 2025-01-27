/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 23:31:52 by iziane            #+#    #+#             */
/*   Updated: 2024/10/26 23:31:54 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	search_contact(PhoneBook *pb)
{
	std::string input;
	std::string action;
	std::string parsing;
	int			input_index;
	Log			log;

	for (std::size_t i = 0; i < pb->amount_contacts; i++)
		pb->print_table(i);
	while (1)
	{
		if (std::cin.eof())
		{
			std::system("clear");
			exit(0) ;
		}
		if (pb->amount_contacts == 0)
			std::cout << "PhoneBook still empty. Enter 'q' to quit: ";
		else
			std::cout << "Enter Index to display (1-8), or 'q' to quit: ";
		std::getline(std::cin, input);
		std::istringstream ss(input);
		if (ss >> action && !(ss >> action))
		{
			if (action == "q")
			{
				std::cout << "Returning\n";
				break ;
			}
		}
		std::istringstream sp(input);
		if (sp >> input_index)
		{
			if ((input_index >= 1 && input_index <= 8)
					&& (size_t)input_index <= pb->amount_contacts && !(sp >> action))
				pb->display_contact_data((size_t)input_index - 1);
			else
			{
				log.mf_set_level(INFO);
				log.mf_info("No contact found under this index");
			}
		}
		else
		{
			log.mf_set_level(ERROR);
			log.mf_error("Invalid Input. Enter 1-8 or 'q' to quit");
		}
	}
}
