#include "phonebook.hpp"

void	add_darkest_secret(Contact *new_contact)
{
	std::string	action;
	std::string	str;
	Log			status;

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, str);
	std::stringstream ss(str);
	ss >> action;
	ss >> action;
	new_contact->add_x(action, new_contact->DARKEST_SECRET);
	new_contact->get_x((new_contact->DARKEST_SECRET));
}

bool	is_valid_nbr(const std::string &nbr)
{
	size_t	start = 0;

	if (nbr.empty() || nbr.size() < 3)
		return (false);
	if (nbr[0] == '+')
		start = 1;
	while (start < nbr.length())
	{
		if (!std::isdigit(nbr[(unsigned char)start]))
			return (false);
		start++;
	}
	return (true);
}

void	add_phone_nbr(Contact *new_contact)
{
	std::string	action;
	std::string	str;
	Log			status;

	while (1)
	{
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

void	add_nickname(Contact *new_contact)
{
	std::string	action;
	std::string	str;

	std::cout << "Enter nickname: ";
	std::getline(std::cin, str);
	std::stringstream ss(str);
	ss >> action;
	new_contact->add_x(action, new_contact->NICKNAME);
	new_contact->get_x((new_contact->NICKNAME));
}

void	add_last_name(Contact *new_contact)
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
		std::cout << "Enter last name: ";
		std::getline(std::cin, str);
		std::stringstream ss(str);
		if (ss >> action && !(ss >> action))
		{
			new_contact->add_x(action, new_contact->LAST_NAME);
			new_contact->get_x((new_contact->LAST_NAME));
			break ;
		}
		else
			status.mf_set_level(ERROR);
			status.mf_error("Please enter valid Last Name (Only name)");
	}
}

void	add_first_name(Contact *new_contact)
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
		std::cout << "Enter first name: ";
		std::getline(std::cin, str);
		std::stringstream ss(str);
		if (ss >> action && !(ss >> action))
		{
			new_contact->add_x(action, new_contact->FIRST_NAME);
			new_contact->get_x((new_contact->FIRST_NAME));
			break ;
		}
		else
		{
			status.mf_set_level(ERROR);
			status.mf_error("Please enter valid Name (Enter one name)");
		}
	}
}

void	add_contact(void)
{
	Contact new_contact;

	add_first_name(&new_contact);
	add_last_name(&new_contact);
	add_nickname(&new_contact);
	add_phone_nbr(&new_contact);
	add_darkest_secret(&new_contact);
}
