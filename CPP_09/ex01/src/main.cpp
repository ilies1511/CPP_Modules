/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:47:28 by iziane            #+#    #+#             */
/*   Updated: 2025/01/01 23:51:55 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	--tool=memcheck		leaks, invalid reads/writes detection
	--tool=callgrind	runtime profiling
	--tool=cachegrind	cache profiling
	--tool=massif		heap memory profiling
	--tool=helgrind		locking order violation detection
	--tool=drd			multithreading error detection

		Leaks Check:
			dorker valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes -v ./ex03.out
*/

#include "../Includes/Tests/test.hpp"
#include "../Includes/Extra/printer.hpp"
#include "Log.hpp"
#include "RPN.hpp"

/*
	Subj-Examples:
		"8 9 * 9 - 9 - 9 - 4 - 1 +" --> 42
		"7 7 * 7 -" --> 42
		"1 2 * 2 / 2 * 2 4 - +" --> 0
*/
int	main(int argc, char **argv)
{
	Log	log("Reverse Polish Notation");

	if (argc < 2)
	{
		log.complain("ERROR", \
		"Expected Program Input", \
		__FILE__, __FUNCTION__, __LINE__);
		log.complain("INFO", "Usage: ./RPN <InputString>");
		return (1);
	}
	else if (argc == 2)
	{
		try
		{
			printer::Header("Command Line Input Mode\n");
			ReversePolishNotation	rpn(argv[1]);
			rpn.processInput();
			std::cout << coloring(std::to_string(rpn.getTop()) + "\n", GREEN);
		}
		catch(const std::exception& e)
		{
			printer::LogException(e, __FILE__, __FUNCTION__, __LINE__);
		}
	}
	else
	{
		try
		{
			printer::Header("Test-Suit Mode\n");
			testrunner::test_printStack();
			testrunner::test_IST_SOLL();
		}
		catch(const std::exception& e)
		{
			printer::LogException(e, __FILE__, __FUNCTION__, __LINE__);
		}
	}
	return (0);
}
