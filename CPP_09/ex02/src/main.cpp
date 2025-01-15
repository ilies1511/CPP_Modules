/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:47:28 by iziane            #+#    #+#             */
/*   Updated: 2025/01/15 00:59:13 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
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
*/
int	main(int argc, char **argv)
{
	Log	log("PmergeMe");

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
		VectorPmergeMe vector(argc, argv);
		DequePmergeMe deque(argc, argv);

		vector.displayOutput();
		deque.displayOutput();
		validateSorting(deque.getContainer(), "Deque");
		validateSorting(vector.getContainer(), "Vector");
	}
	catch(const std::exception& e)
	{
		printer::LogException(e, __FILE__, __FUNCTION__, __LINE__);
	}
	return (0);
}
