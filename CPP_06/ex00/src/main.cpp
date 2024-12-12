/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:50:56 by iziane            #+#    #+#             */
/*   Updated: 2024/12/12 20:29:13 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_06.hpp"
#include "../Includes/Extra/printer.hpp"

/*
		Leaks Check:
			dorker valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ex03.out
*/
int	main(int argc, char **argv)
{
	if (argc <= 1 || argc > 2)
	{
		testrunner::interactive();
		// std::cerr << "Enter literal to be converted\n";
		return (1);
	}
	printer::Header("TESTRUNNER");
	ScalarConverte::convert(argv[1]);
	return (0);
}
