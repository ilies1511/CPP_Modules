/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:50:36 by iziane            #+#    #+#             */
/*   Updated: 2024/11/21 09:50:40 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <cassert>

namespace testrunner
{
	/// @brief Test, um zu sehen ob Materia bei mitlungenem equip richtig aufgenommen wir vom Floor
	void integratedMateriaSourceTest()
	{
		printer::Header("TEST: Integrated MateriaSource Functionality");
		Floor floor;
		// 1. Erstellen von MateriaSource und Characters
		MateriaSource* src = new MateriaSource();
		Character* me = new Character("me", &floor);
		Character* bob = new Character("bob", &floor);
		// 2. Lernen von Materias
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		// 3. Ausrüsten der Materias beim Charakter
		AMateria* iceMateria = src->createMateria("ice");
		AMateria* cureMateria = src->createMateria("cure");
		me->equip(iceMateria);
		me->equip(cureMateria);
		// 4. Verwendung der Materias
		printer::PrintMessage("Using Materias:", printer::MessageType::HEADER);
		me->use(0, *bob); // Ice Materia -> erwartet: "* shoots an ice bolt at bob *"
		me->use(1, *bob); // Cure Materia -> erwartet: "* heals bob's wounds *"
		// 5. Test für leere Slots und Überfüllen
		AMateria* extraMateria = src->createMateria("ice");
		me->equip(extraMateria); // Dritter Slot wird belegt
		me->equip(src->createMateria("cure")); // Vierter Slot wird belegt
		me->equip(src->createMateria("ice")); // Ignoriert, da das Inventar voll ist, wird von dyn, Array Floor aufgenommen
		// Überprüfen, ob das Inventar korrekt funktioniert
		printer::PrintMessage("Testing full inventory:", printer::MessageType::HEADER);
		me->use(3, *bob); // Letzter Slot -> erwartet: "* heals bob's wounds *"
		me->use(4, *bob); // Außerhalb des Inventars -> keine Aktion erwartet
		// 6. Unbekannte Materia anfordern
		AMateria* unknownMateria = src->createMateria("fire");
		if (!unknownMateria)
			printer::PrintMessage("Unknown Materia (fire) not created as expected.", printer::MessageType::SUCCESS);
		delete me;
		delete bob;
		delete src;
		printer::PrintMessage("Integrated TEST PASSED: MateriaSource works in context.", printer::MessageType::SUCCESS);
	}

	/// @brief TEST for using Materia on multiple targets
	void useMultipleTargets(void)
	{
		Floor sharedFloor;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("Bebsi", &sharedFloor);
		ICharacter* bob = new Character("Gwyneth", &sharedFloor);
		ICharacter* alice = new Character("Sah'ween", &sharedFloor);

		AMateria* tmp1 = src->createMateria("ice");
		me->equip(tmp1);

		// Use the ice Materia on multiple targets
		me->use(0, *bob);   // Should shoot an ice bolt at Bob
		me->use(0, *alice); // Should shoot an ice bolt at Alice

		delete me;
		delete bob;
		delete alice;
		delete src;
	}

	/// @brief TEST for Floor resizing and overflow handling
	void floorOverflowTest(void)
	{
		Floor sharedFloor;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me", &sharedFloor);
		AMateria* tmp1 = src->createMateria("ice");
		AMateria* tmp2 = src->createMateria("cure");
		// Try to equip more than 4 Materias (inventory is of size 4)
		me->equip(tmp1);
		me->equip(tmp2);
		me->equip(src->createMateria("ice"));
		me->equip(src->createMateria("cure"));
		printer::PrintMessage("PRE-FLOOR: Equipping 5 Materias", printer::MessageType::HEADER);
		std::cout << coloring("Floor Capacity: " + std::to_string(sharedFloor.getFloorCapacity()), DARK_GRAY) << "\n";
		// Adding a fifth Materia should trigger resizing of the floor
		printer::PrintMessage("PRE-FLOOR: Equipping 5 Materias", printer::MessageType::HEADER);
		printer::print_floor(&sharedFloor);
		// Now let's unequip some of the items and check the floor
		me->unequip(0);  // This will add the first Materia (ice) to the floor
		printer::PrintMessage("PRE-FLOOR: Capacity", printer::MessageType::HEADER);
		std::cout << coloring("Floor Capacity: " + std::to_string(sharedFloor.getFloorCapacity()), DARK_GRAY) << "\n";
		me->unequip(1);  // This will add the first Materia (ice) to the floor
		std::cout << coloring("Floor Capacity: " + std::to_string(sharedFloor.getFloorCapacity()), DARK_GRAY) << "\n";
		me->unequip(2);  // This will add the first Materia (ice) to the floor
		std::cout << coloring("Floor Capacity: " + std::to_string(sharedFloor.getFloorCapacity()), DARK_GRAY) << "\n";
		me->unequip(3);  // This will add the first Materia (ice) to the floor
		// me->equip(src->createMateria("cure"));
		printer::PrintMessage("POST-FLOOR: Unequip four Materia", printer::MessageType::HEADER);
		printer::print_floor(&sharedFloor);
		delete me;
		delete src;
	}

	/// @brief TEST for edge cases when unequipping
	void unequipEdgeCases(void)
	{
		Floor sharedFloor;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		ICharacter* me = new Character("me", &sharedFloor);
		AMateria* tmp1 = src->createMateria("ice");
		me->equip(tmp1); // Equip an Slot 0
		// Test for unequipping from an empty slot (slot 1 is empty)
		me->unequip(1);  // Should print a message saying no Materia to unequip
		// Test for unequipping from a valid slot (slot 0)
		me->unequip(0);  // Should remove the Materia from slot 0 and add it to the floor
		// Test unequipping again from the same slot (should now be empty)
		me->unequip(0);  // Should print a message saying "No Inventory at slot 0"
		printer::PrintMessage("POST UNEQUIP FLOOR:", printer::MessageType::HEADER);
		// Floor should now contain one Materia (ice)
		printer::print_floor(&sharedFloor);
		delete me;
		delete src;
	}

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

} // namespace testrunnner
