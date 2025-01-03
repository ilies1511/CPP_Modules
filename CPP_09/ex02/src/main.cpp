/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:47:28 by iziane            #+#    #+#             */
/*   Updated: 2025/01/03 05:06:35 by iziane           ###   ########.fr       */
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
	if (argc < 2)
	{
		log.complain("ERROR", \
		"Expected Program Input", \
		__FILE__, __FUNCTION__, __LINE__);
		log.complain("INFO", "Usage: ./PmergeMe <Input: Positive integer sequence>");
		return (1);
	}
	VectorPmergeMe vector(argc, argv);
	vector.sort();
	DequePmergeMe deque(argc, argv);
	deque.sort();
	//[...]
	return (0);
}
