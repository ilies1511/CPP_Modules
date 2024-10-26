#include "phonebook.hpp"
#include <regex>

bool	is_valid_nbr(std::string &nbr)
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
bool	is_valid_phone_nbr(std::string &nbr)
{
	std::regex phonePattern("^(\\+\\d{1,3}|00\\d{1,3}|\\d{1,3}|\\d{2,3})\\d{0,10}$");

	if (nbr.empty() || nbr.size() < 3 ||
		!std::regex_match(nbr, phonePattern) )
		return (false);
	return (true);
}

bool	is_valid_name(std::string &str)
{
	std::string	action;

	std::stringstream ss(str);
	if (ss >> action && !(ss >> action))
	{
		str.assign(action);
		return (true);
	}
	return (false);
}

void	add_universal_template(Contact *new_contact, Contact::Add type,
		const std::string &prompt, bool (*validator)(std::string&) = nullptr)
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
		std::cout << "Enter " << prompt << ": ";
		std::getline(std::cin, str);
		std::stringstream ss(str);
		if (validator && !validator(str))
		{
			status.mf_set_level(ERROR);
			status.mf_error("Please enter valid " + prompt);
			continue ;
		}
		new_contact->add_x(str, type);
		new_contact->get_x((type));
		break ;
	}
}

void	add_contact(PhoneBook *pb)
{
	Contact		new_contact;

	// std::cout << "PRE ADD Operation: " << pb->amount_contacts << '\n';
	add_universal_template(&new_contact, Contact::FIRST_NAME, "FirstName", is_valid_name);
	add_universal_template(&new_contact, Contact::LAST_NAME, "LastName", is_valid_name);
	add_universal_template(&new_contact, Contact::NICKNAME, "NickName", is_valid_name);
	add_universal_template(&new_contact, Contact::PHONE_NBR, "PhoneNumber", is_valid_phone_nbr);
	add_universal_template(&new_contact, Contact::DARKEST_SECRET, "DarkestSecret");
	pb->add_contact_to_pb(new_contact);
	// std::cout << "POST ADD Operation: " << pb->amount_contacts << '\n';
	// std:: cout << coloring("\nContact succesfully added\n", GREEN);
	// pb.print_contact_data(new_contact, 0);
}
