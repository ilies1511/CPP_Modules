
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "printer.hpp"

/// @brief TEST from subj.pdf
void	subj()
{
	Floor	sharedFloor;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me", &sharedFloor);
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob", &sharedFloor);
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}

/// @brief TEST aims to check functionallity of floor --> dynamic array
void	cwazy(void)
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
	printer::PrintMessage("Character Equips Materia:", printer::MessageType::HEADER);
	me->equip(tmp);
	me->equip(tmp2);
	me->equip(tmp3);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	printer::PrintMessage("PRE FLOOR:", printer::MessageType::HEADER);
	//Check Content of Floor PRE (here should be empty)
	printer::print_floor(&sharedFloor);
	//Check Content of Floor (here should hold two items)
	printer::PrintMessage("POST FLOOR:", printer::MessageType::HEADER);
	me->unequip(0);
	// me->unequip(1);
	printer::print_floor(&sharedFloor);
	ICharacter* bob = new Character("bob", &sharedFloor);
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}

int	main(void)
{
	/*
		Leaks Check:
			dorker valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ex03.out
	*/
	// subj();
	cwazy();
	return (0);
}
