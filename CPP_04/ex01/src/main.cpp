
// #include "Animal.hpp"
#include "WrongAnimal.hpp"
// #include "Cat.hpp"
#include "WrongCat.hpp"
// #include "Dog.hpp"
#include "../Includes/Dog.hpp"
#include "../Includes/Cat.hpp"
#include "../Includes/Animal.hpp"
#include "extra.hpp"
#include <new>
#include <string>
#include <sstream>

/*
	Leaks Check:
		dorker valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ex00.out
	rm link between repos (ex00, ex01):
		1.Cmd + Shift + P
		2.Reset IntelliSense Database
		3.Close and reopen VS Code after resetting the cache
		4. .vscode -> c_cpp_properties.json -> Explicit Paths: By specifying ${workspaceFolder}/Includes and ${workspaceFolder}/src
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
	int	ex01_brain()
	{
		printer::Header("EX01_BRAIN TEST");
		Cat	megaMiau;
		Cat	MINIMiau;
		Dog	confusedDog;

		megaMiau.getBrain()->setIdeas(0, "alooooooo");
		MINIMiau = megaMiau;
		MINIMiau.getBrain()->setIdeas(1, "ALOOOOO");

		confusedDog.getBrain()->setIdeas(0, "MiauMiau");
		Dog	normalDog(confusedDog);//Normal Dog has own brain and overwrites idea
		normalDog.getBrain()->setIdeas(1, "WufWuf");
		for (size_t i = 0; i < 2; i++)
		{
			std::cout << coloring("EX01_BRAIN TEST inside LOOP Interation: " + std::to_string(i), ORANGE) << "\n";
			std::cout << "megaMiau: " << megaMiau.getBrain()->getIdeas(i) << "\n";
			std::cout << "MINIMiau: " << MINIMiau.getBrain()->getIdeas(i) << "\n";
			std::cout << "confudesDog: " << confusedDog.getBrain()->getIdeas(i) << "\n";
			std::cout << "normalDog: " << normalDog.getBrain()->getIdeas(i) << "\n";
		}
		return (EXIT_SUCCESS);
	}

	int	ex01()
	{
		printer::Header("ZOO Array Filler");
		// size_t	len = 10;
		Animal*	zoo[10];

		for (size_t i = 0; i < 10; i++)
		{
			if (i % 2 == 0)
				zoo[i] = new Cat;
			else
				zoo[i] = new Dog;
		}
		//Destructor LOOP
		printer::Header("ZOO Array Deleter");
		for (size_t i = 0; i < 10; i++)
		{
			delete zoo[i];
		}
		return (EXIT_SUCCESS);
	}
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

	void	test_runner()
	{
		// subj();
		// copy_constructor();
		// copy_assigment();
		ex01_brain();
		// ex01();
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
