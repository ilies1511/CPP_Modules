/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:45:44 by iziane            #+#    #+#             */
/*   Updated: 2024/11/21 09:45:45 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "extra.hpp"
#include <new>
#include <string>
#include <sstream>

/*
	Leaks Check:
		dorker valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ex00.out
*/

//subj.pdf Example
void	subj_example(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
}

namespace printer
{
	enum class MessageType { INFO, PROMPT, ERROR, HEADER };

	//Usage: printer::PrintMessage("Memory allocation failed for " + header, printer::MessageType::ERROR);
	void PrintMessage(const std::string &message, MessageType type = MessageType::INFO)
	{
		std::string color;
		switch (type)
		{
			case MessageType::INFO:		color = PURPLE;	break;
			case MessageType::PROMPT:	color = BLUE;	break;
			case MessageType::ERROR:	color = RED;	break;
			case MessageType::HEADER:	color = ORANGE;	break;
		}
		std::cout << coloring(message, color) << "\n";
	}

	void	Header(const std::string &Input)
	{
		std::cout << coloring(Input, ORANGE) << "\n";
	}

	void	print_Interactive(const std::string &Input)
	{
		std::cout << coloring(Input, BLUE);
	}

	void	print_invalidInput()
	{
		std::cout << \
			coloring("[INFO]: Invalid Command. USAGE: <animal> <cat> <dog> <wronganimal> <wrongcat> <clear> <exit>", RED) << "\n";
	}

	template <typename DataType>
	void PrintUniversal(const DataType &animal)
	{
		std::cout << animal.getType() << "\n";
		animal.makeSound();
	}
}

namespace runner
{
	template <typename Datatype>
	void	TestAnimalUniversal(const std::string &header)
	{
		printer::Header(header);
		const Datatype *animal = new (std::nothrow) Datatype();
		if (!animal)
		{
			// std::cerr << "Memory allocation failed for " << header << "\n";
			printer::PrintMessage("Memory allocation failed for " + header, printer::MessageType::ERROR);
			return ;
		}
		printer::PrintUniversal(*animal);
		delete animal;
	}
}

namespace noninteractive
{
	void	copy_assigment()
	{
		printer::Header("copy assigment");

		Animal	og_animal;
		og_animal.setType("Loewe");
		Animal	animal2 = og_animal;

		std::cout << og_animal.getType() << "\n";
		std::cout << animal2.getType() << "\n";
	}

	void	copy_constructor()
	{
		printer::Header("copy constructor");

		Animal	og_animal;
		og_animal.setType("Loewe");
		Animal	animal2(og_animal);

		std::cout << og_animal.getType() << "\n";
		std::cout << animal2.getType() << "\n";
	}

	void	subj(void)
	{
		runner::TestAnimalUniversal<Animal>("Animal");
		runner::TestAnimalUniversal<Dog>("Dog");
		runner::TestAnimalUniversal<Cat>("Cat");
		runner::TestAnimalUniversal<WrongAnimal>("WrongAnimal");
		runner::TestAnimalUniversal<WrongCat>("WrongCat");
	}

	void	subj_real()
	{
		printer::Header("TEST: subj_real");
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete (meta);
		delete (i);
		delete (j);
	}

	void	subj_real_wrongAnimal()
	{
		printer::Header("TEST: subj_real_wrongAnimal");
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //Should output the WrongAnimal sound!
		meta->makeSound();

		delete (meta);
		delete (i);
		return ;
	}

	void	test_runner()
	{
		subj_real();
		subj_real_wrongAnimal();
		subj();
		copy_constructor();
		copy_assigment();
	}
}

namespace interactive
{
	void	ExecuteCommand(const std::string& action)
	{
		if (action == "animal")
			runner::TestAnimalUniversal<Animal>("Animal");
		else if (action == "cat")
			runner::TestAnimalUniversal<Cat>("Cat");
		else if (action == "dog")
			runner::TestAnimalUniversal<Dog>("Dog");
		else if (action == "wronganimal")
			runner::TestAnimalUniversal<WrongAnimal>("WrongAnimal");
		else if (action == "wrongcat")
			runner::TestAnimalUniversal<WrongCat>("WrongCat");
		else if (action == "clear")
			std:: system("clear");
		else if (action == "exit")
		{
			std:: system("clear");
			exit(0);
		}
		else
			printer::print_invalidInput();
	}

	//Checks wether input is valid
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

	void	test_runner_interactive()
	{
		std::string	command;
		std::string	action;

		while (1)
		{
			if (std::cin.eof())
			{
				std:: system("clear");
				exit(0);
			}
			printer::print_Interactive("Enter a command: ");
			std::getline(std::cin, command);
			std::stringstream ss(command);
			ss >> action;
			if (!is_valid_name(command))
			{
				printer::print_invalidInput();
				continue ;
			}
			ExecuteCommand(action);
		}
	}
}

int main(int argc, char **argv)
{
	(void)argv;
	if (argc == 1)
	{
		noninteractive::test_runner();
		return (EXIT_SUCCESS);
	}
	else if (argc == 2)
	{
		std:: system("clear");
		interactive::test_runner_interactive();
		return (EXIT_SUCCESS);
	}
	else
	{
		// std::cerr << "Usage: " << argv[0] << " [-i]" << std::endl;
		printer::PrintMessage("Usage: " + static_cast<std::string>(argv[0]) + " [-i]", printer::MessageType::INFO);
		return (EXIT_FAILURE);
	}
	return (0);
}
