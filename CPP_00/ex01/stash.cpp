#include "phonebook.hpp"
#include <regex>

bool	is_valid_nbr(std::string &nbr);

void	add_darkest_secret(Contact *new_contact)
{
	std::string	action;
	std::string	str;
	Log			status;

	while (1)
	{
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, str);
		std::stringstream ss(str);
		if (!(ss >> action))
		{
			status.mf_set_level(ERROR);
			status.mf_error("Please enter valid input...)");
			continue ;
		}
		new_contact->add_x(str, new_contact->DARKEST_SECRET);
		// new_contact->add_x(action, new_contact->DARKEST_SECRET);
		new_contact->get_x((new_contact->DARKEST_SECRET));
		break;
	}
}

void	add_phone_nbr(Contact *new_contact)
{
	std::string	action;
	std::string	str;
	Log			status;

	while (1)
	{
		if (std::cin.eof())
		{
			std::system("clear");
			exit(1);
		}
		std::cout << "Enter phone number: ";
		std::getline(std::cin, str);
		std::stringstream ss(str);
		if (ss >> action  && is_valid_nbr(action) && !(ss >> action))
		{
			new_contact->add_x(action, new_contact->PHONE_NBR);
			new_contact->get_x((new_contact->PHONE_NBR));
			break ;
		}
		else
		{
			status.mf_set_level(ERROR);
			status.mf_error("Please enter valid number((+)12345678...)");
		}
	}
}

void	add_template(Contact *new_contact, Contact::Add type, const std::string &input)
{
	std::string	action;
	std::string	str;
	Log			status;

	while (1)
	{
		if (std::cin.eof())
		{
			std::system("clear");
			exit(1);
		}
		std::cout << "Enter " << input << ": ";
		std::getline(std::cin, str);
		std::stringstream ss(str);
		if (ss >> action && !(ss >> action))
		{
			new_contact->add_x(action, type);
			new_contact->get_x((type));
			break ;
		}
		else
		{
			status.mf_set_level(ERROR);
			status.mf_error("Please enter valid " + input);
		}
	}
}

void	add_contact_stash(PhoneBook *pb)
{
	Contact		new_contact;

	std::cout << "PRE ADD Operation: " << pb->amount_contacts << '\n';
	add_template(&new_contact, Contact::FIRST_NAME, "FIRST_NAME");
	add_template(&new_contact, Contact::LAST_NAME, "LAST NAME");
	add_template(&new_contact, Contact::NICKNAME, "NICK_NAME");
	add_phone_nbr(&new_contact);
	add_darkest_secret(&new_contact);
	// pb->add_contact_to_pb_stash(new_contact);
	std::cout << "POST ADD Operation: " << pb->amount_contacts << '\n';
	// std:: cout << coloring("\nContact succesfully added\n", GREEN);
	// pb.print_contact_data(new_contact, 0);
}
