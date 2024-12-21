/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:50:36 by iziane            #+#    #+#             */
/*   Updated: 2024/12/21 23:03:07 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Tests/test.hpp"
#include "Span.hpp"
#include <random>
#include <ctime>

// #include "test.hpp"

//IMPLEMENTATION
namespace testrunner
{
	int	ex01_subj(void)
	{
		Span	sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		if (sp.shortestSpan() != 2)
			return (EXIT_FAILURE);
		if (sp.longestSpan() != 14)
			return (EXIT_FAILURE);
		std::cout << coloring(std::string("Function '") + __FUNCTION__ + "()' passed all the tests", GREEN) << "\n";
		// std::cout << coloring(std::string("Function: ") + __FUNCTION__, GREEN) << std::endl;
		return (EXIT_SUCCESS);
	}

	void	test_addRange(void)
	{
		try
		{
			Span sp(100);
			//Vector, being filled with random data
			std::vector<int> vecFiller(100);
			srand(static_cast<unsigned int>(time(NULL)));
			for (size_t i = 0; i < 100; i++)
			{
				vecFiller[i] = rand() % std::numeric_limits<int>::max() - 1;
			}
			sp.addRange(vecFiller.begin(), vecFiller.end());
			for (size_t i = 0; i < sp.getSize(); i++)
			{
				std::cout << sp[i];
				if (i < sp.getSize() - 1)
					std::cout << ", ";
			}
			std::cout << "\n";
		}
		catch(const std::exception& e)
		{
			printer::LogException(e, __FILE__, __FUNCTION__, __LINE__);
		}
	}
} // namespace testrunnner
