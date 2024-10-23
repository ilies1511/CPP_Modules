#include "phonebook.hpp"

void	generate_phonebook()
{
	std::string	command;
	PhoneBook	pb;
	Log			log;

	while (true)
	{
		if (std::cin.eof())
		{
			std::cout << "\nEnd of input. Exiting." << std::endl;
			exit(1);
		}
		std::cout << "Enter command: ";
		std::getline(std::cin, command);
		std::stringstream ss(command);
		std::string action;
		// Extract the first word as the action
		ss >> action;
		if (action == "ADD" && !(ss >> action))
			std::cout << "Parser is good\n";
		else
			std::cout << "Khara Parser\n";
		// else if (command == "SEARCH")
		// 	pb.search_contact();
		// else if (command == "EXIT")
		// 	break;
		// else
		// {
		// 	log.mf_set_level(INFO);
		// 	log.mf_info("Invalid command.\nAvailable Commands:\n\"ADD\", \"SEARCH\", \"REMOVE\" or \"EXIT\"!");
		// }
		// 	std::cout << "Invalid command.\nPlease use \"ADD\", \"SEARCH\" or \"EXIT\"!" << std::endl;
		// std::system("clear");
	}
}

int main(int argc, char **argv)
{
	Log log;
	Contact contact;
	PhoneBook pb;

	(void)argc;
	(void)argv;
	// greet the user
	std::string name;
	std::cout << "What is your name? ";
	std::getline(std::cin, name);
	std::cout << "Hello " << name << ", nice to meet you.\n";

	// read file line by line
	std::istringstream input;
	input.str("1\n2\n3\n4\n5\n6\n7\n");
	int sum = 0;
	for (std::string line; std::getline(input, line);)
		sum += std::stoi(line);
	std::cout << "\nThe sum is " << sum << ".\n\n";
	generate_phonebook();
	return (0);
}
