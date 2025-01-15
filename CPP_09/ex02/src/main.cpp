/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:47:28 by iziane            #+#    #+#             */
/*   Updated: 2025/01/15 22:42:08 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	jot -r 3000 1 1000 | tr '\n' ' '

	find . -type f -name 'Makefile' -execdir make fclean \;

	Leaks Check:
		dorker valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes -v ./ex03.out
*/

#include "../Includes/Tests/test.hpp"
#include "../Includes/Extra/printer.hpp"
#include "Log.hpp"
#include "PmergeMe.hpp"
#include "VectorPmergeMe.hpp"
#include "DequePmergeMe.hpp"

/*
	Odd Sequence: 9 1 8 2 7 3 6 4 5 0
	Even Sequence: 9 1 8 2 7 3 6 4 5

	1000 950 900 850 800 750 700 650 600 550 500 450 400 350 300 250 200 150 100 50 0
	1 1000 2 999 3 998 4 997 5 996 6 995 7 994 8 993 9 992 10 991
	5 5 5 10 10 10 15 15 15 20 20 20 25 25 25 30 30 30
	1 10000 2 9999 3 9998 4 9997 5 9996 6 9995 7 9994 8 9993 9 9992
	1 2 3 4 5 7 6 8 9 10 12 11 14 13 16 15 18 17 20 19
	12345 987 65432 321 45678 789 23456 987 34567 123 56789 321 67890 456
	100 100 100 100 100 100 100 100 100 100 101
	1 100 2 99 3 98 4 97 5 96 6 95 7 94 8 93 9 92 10
	10 1 9 2 8 3 7 4 6 5 15 6 14 7 13 8 12 9 11 10
	5 1 9 2 8 4 7 3 6 0 10 20 30 40 50 15 25 35 45
*/
int	main(int argc, char **argv)
{
	Log	log("PmergeMe");

	(void)argc;
	(void)argv;
	if (argc < 3)
	{
		log.complain("ERROR", \
		"Expected Program Input", \
		__FILE__, __FUNCTION__, __LINE__);
		log.complain("INFO", "Usage: ./PmergeMe <Input: Positive integer sequence>");
		return (1);
	}
	try
	{
		// VectorPmergeMe vector;
		// DequePmergeMe deque;
		VectorPmergeMe vector(argc, argv);
		DequePmergeMe deque(argc, argv);

		vector.displayOutput();
		deque.displayOutput();
		validateSorting(vector.getContainer(), "Vector");
		validateSorting(deque.getContainer(), "Deque");
	}
	catch(const std::exception& e)
	{
		printer::LogException(e, __FILE__, __FUNCTION__, __LINE__);
	}
	return (0);
}
