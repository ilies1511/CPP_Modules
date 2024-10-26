/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methodes_pb.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 21:16:52 by iziane            #+#    #+#             */
/*   Updated: 2024/10/26 21:18:44 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"


void PhoneBook::add_contact_to_pb(Contact new_contact)
{
	if (amount_contacts == 8)
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

void PhoneBook::print_contact_data(Contact new_contact, std::size_t index)
{
	(void)new_contact;
	contacts[index].get_all();
}

void	PhoneBook::print_table(std::size_t index)
{
	contacts[index].get_formated(index);
}

void	PhoneBook::display_contact_data(size_t index)
{
	std::system("clear");
	contacts[index].get_all();
}
