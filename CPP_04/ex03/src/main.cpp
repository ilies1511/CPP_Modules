
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "extra.hpp"

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
			coloring("[INFO]: Invalid Command. USAGE: <cat> <dog> <wronganimal> <wrongcat> <clear> <exit>", RED) << "\n";
	}

	void	print_floor(Floor	*sharedFloor)
	{
		for (size_t i = 0; i < (sharedFloor->getFloorSize()); i++)
			std::cout << "Item[" << i << "]: " << sharedFloor->getMateria(i)->getType() << "\n";
	}
}


/// @brief
/// @param
/// @return
int	main(void)
{
	Floor	sharedFloor;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me", &sharedFloor);
	AMateria* tmp;
	AMateria* tmp2;
	AMateria* tmp3;
	tmp = src->createMateria("ice");
	tmp2 = src->createMateria("ice");
	tmp3 = src->createMateria("ice");
	me->equip(tmp);
	me->equip(tmp2);
	me->equip(tmp3);
	tmp = src->createMateria("cure");
	std::cout << coloring("PRE FLOOR: \n", BLUE);
	//Check Content of Floor PRE (here should be empty)
	printer::print_floor(&sharedFloor);
	//Check Content of Floor (here should hold two items)
	std::cout << coloring("POST FLOOR: \n", BLUE);
	me->unequip(0);
	// me->unequip(1);
	printer::print_floor(&sharedFloor);
	ICharacter* bob = new Character("bob", &sharedFloor);
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}
