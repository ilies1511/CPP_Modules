/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:47:28 by iziane            #+#    #+#             */
/*   Updated: 2024/12/19 22:40:41 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Tests/test.hpp"
#include "../Includes/Extra/printer.hpp"

int	main(void)
{
	/*
		Leaks Check:
			dorker valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ex03.out
	*/
	printer::Header("TESTS CPP08");

	try
	{
		std::vector<int> numbers = {1, 2, 3, 4, 5};

		auto it = easyfind(numbers, -12);
		std::cout << "Found: " << *it << std::endl;

		// Test case: Value not found
		easyfind(numbers, 10); // Throws NotFoundException
	}
	catch (const std::exception& e)
	{
		printer::LogException(e, __FILE__, __FUNCTION__, __LINE__);
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
