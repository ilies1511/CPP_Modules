
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "extra.hpp"
#include <new>

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

	void	Universel_Animal(const Animal &animal)
	{
		std::cout << animal.getType() << "\n";
		animal.makeSound();
	}

	void	Universel_WrongAnimal(const WrongAnimal &wronganimal)
	{
		std::cout << wronganimal.getType() << "\n";
		wronganimal.makeSound();
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
	void	wrong_animal()
	{
		try
		{
			const WrongAnimal* meta = new WrongAnimal();
			const WrongAnimal* i = new WrongCat();

			printer::Header("Wrong Animal");
			printer::Universel_WrongAnimal(*meta);
			printer::Universel_WrongAnimal(*i);
			delete i;
			delete meta;
		}
		catch (const std::bad_alloc &e)
		{
			std::cerr << "Memory allocation error: " << e.what() << std::endl;
		}
	}

	void	subj(void)
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		printer::Header("Normal Animal - Welcome in the ZOO");
		printer::Universel_Animal(*meta);
		printer::Universel_Animal(*j);
		printer::Universel_Animal(*i);
		delete j;
		delete i;
		delete meta;
	}

	void	test_runner()
	{
		subj();
		wrong_animal();
	}
}

int main(int argc, char **argv)
{
	(void)argv;
	if (argc == 1)
	{
		noninteractive::test_runner();
		return (EXIT_SUCCESS);
		//Geht einfach durch alle Tests ohne auf einen spezifisch einzugehen
	}
	else if (argc == 2)
	{
		;//Hier kommt man dann in den Interactiven Modus rein.
	}
	else
	{
		std::cout << "[USAGE]: " << "<> or <Animal> or <Cat> <Dog> <WrongAnimal> <WrongCat>" <<"\n";
		return (EXIT_FAILURE);
	}
	return (0);
}
