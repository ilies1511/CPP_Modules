/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:50:56 by iziane            #+#    #+#             */
/*   Updated: 2024/12/09 20:17:41 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_06.hpp"
#include "../Includes/Extra/printer.hpp"

/*
		Leaks Check:
			dorker valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ex03.out
*/
int	main(void)
{
	printer::Header("TESTRUNNER");
	testrunner::TypeDetectionTest();
	return (0);
}
