/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:47:28 by iziane            #+#    #+#             */
/*   Updated: 2024/12/29 03:20:07 by iziane           ###   ########.fr       */
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
#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	printer::Header("TESTS CPP09");
	Log	log("Bitcoin Exchange");

	if (argc != 2)
	{
		log.complain("ERROR", \
		"Expected Program Input", \
		__FILE__, __FUNCTION__, __LINE__);
		log.complain("INFO", "Usage: ./btc <*.txt>");
		return (1);
	}
	BitcoinExchange bitcoin(argv[1]);
	bitcoin.fileToMap();
	// bitcoin.printMap();
	// std::cout << "Size: " << bitcoin.getSize() << "\n";
	// std::cout << "Exchange Rate: " << bitcoin.getExchangeRat("2022-03-29") << "\n";
	if (bitcoin.checkInputFile())
		std::cout << coloring("\nSUCCESS\n", GREEN);
	return (0);
}
