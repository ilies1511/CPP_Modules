
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "extra.hpp"
#include <new>
#include <sstream>

/*
	Leaks Check:
		dorker valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ex00.out
*/

namespace printer
{
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

namespace noninteractive
{
	template <typename Datatype>
	void	TestAnimalUniversal(const std::string &header)
	{
		printer::Header(header);
		const Datatype *animal = new (std::nothrow) Datatype();
		if (!animal)
		{
			std::cerr << "Memory allocation failed for " << header << "\n";
			return ;
		}
		printer::PrintUniversal(*animal);
		delete animal;
	}

	void	subj(void)
	{
		TestAnimalUniversal<Animal>("Animal");
		TestAnimalUniversal<Dog>("Dog");
		TestAnimalUniversal<Cat>("Cat");
		TestAnimalUniversal<WrongAnimal>("WrongAnimal");
		TestAnimalUniversal<WrongCat>("WrongCat");
	}

	void	test_runner()
	{
		subj();
		// wrong_animal();
	}
}

namespace interactive
{
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
			if (action == "animal")
				noninteractive::TestAnimalUniversal<Animal>("Animal");
			else if (action == "cat")
				noninteractive::TestAnimalUniversal<Cat>("Cat");
			else if (action == "dog")
				noninteractive::TestAnimalUniversal<Dog>("Dog");
			else if (action == "wronganimal")
				noninteractive::TestAnimalUniversal<WrongAnimal>("WrongAnimal");
			else if (action == "wrongcat")
				noninteractive::TestAnimalUniversal<WrongCat>("WrongCat");
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
		interactive::test_runner_interactive();
		return (EXIT_SUCCESS);
	}
	else
	{
		std::cout << "[USAGE]: " << "<> or <Animal> or <Cat> <Dog> <WrongAnimal> <WrongCat>" <<"\n";
		return (EXIT_FAILURE);
	}
	return (0);
}
