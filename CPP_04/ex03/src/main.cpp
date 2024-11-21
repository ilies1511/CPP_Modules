
// #include "MateriaSource.hpp"
// #include "AMateria.hpp"
// #include "Character.hpp"
// #include "Ice.hpp"
// #include "Cure.hpp"
// #include "printer.hpp"

#include "tests.hpp"

int	main(void)
{
	/*
		Leaks Check:
			dorker valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ex03.out
	*/
	testrunner::subj();
	testrunner::cwazy();
	testrunner::unequipEdgeCases();
	testrunner::floorOverflowTest();
	testrunner::useMultipleTargets();
	return (0);
}
