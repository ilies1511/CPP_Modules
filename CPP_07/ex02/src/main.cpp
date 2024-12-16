/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:47:28 by iziane            #+#    #+#             */
/*   Updated: 2024/12/16 22:37:56 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Tests/test.hpp"

int	main(void)
{
	/*
		Leaks Check:
			dorker valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ex03.out
	*/
	printer::Header("TESTS CPP07 EX02");
	printer::Header("\nSubj Test");
	testrunner::subj_TEST();
	printer::Header("\nDataType: String");
	testrunner::stringArray();
	printer::Header("\nDataType: own");
	testrunner::ownDataType();
	printer::Header("\nEmpty Array");
	testrunner::emptyArray();
	printer::Header("\nAllocation TEST");
	testrunner::allocation();
	return (0);
}
