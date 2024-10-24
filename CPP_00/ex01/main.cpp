#include "phonebook.hpp"

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
		// Extract the first word as the action
		ss >> action;
		if (action == "ADD" && !(ss >> action))
			add_contact();
		else if (command == "SEARCH")
			;// pb.search_contact();
		else if (command == "REMOVE")
			;// pb.search_contact();
		else if (action == "EXIT" && !(ss >> action))
		{
			std:: system("clear");
			break;
		}
		else if (std::cin.eof())
		{
			std:: system("clear");
			exit(1);
		}
		else
		{
			log.mf_set_level(INFO);
			log.mf_info("Invalid command. Available Commands:\n\"ADD\", \"SEARCH\", \"REMOVE\" or \"EXIT\"!");
		}
	}
}

int main(int argc, char **argv)
{
	Log log;
	Contact contact;
	PhoneBook pb;

	(void)argc;
	(void)argv;
	std::system("clear");
	generate_phonebook();
	return (0);
}
