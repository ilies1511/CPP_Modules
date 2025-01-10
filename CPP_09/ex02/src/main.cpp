/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:47:28 by iziane            #+#    #+#             */
/*   Updated: 2025/01/10 22:10:18 by iziane           ###   ########.fr       */
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
		VectorPmergeMe vector(argc, argv);
		DequePmergeMe deque(argc, argv);
		//[...]
		// vector.processInput();
		vector.displayOutput();
		if (!std::is_sorted(vector.getContainer().begin(), vector.getContainer().end()))
			throw (std::runtime_error("Failed to sort sequence ! Still unsorted !"));
		deque.displayOutput();
	}
	catch(const std::exception& e)
	{
		printer::LogException(e, __FILE__, __FUNCTION__, __LINE__);
	}
	return (0);
}
