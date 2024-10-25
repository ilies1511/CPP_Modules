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

void generate_phonebook()
{
	std::string	command;
	std::string	action;
	PhoneBook	pb;
	Log			log;

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
