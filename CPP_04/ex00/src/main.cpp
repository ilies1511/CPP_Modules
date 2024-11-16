
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
