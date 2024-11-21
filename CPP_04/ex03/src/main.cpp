/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:49:55 by iziane            #+#    #+#             */
/*   Updated: 2024/11/21 09:49:56 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
	testrunner::integratedMateriaSourceTest();

	return (0);
}
