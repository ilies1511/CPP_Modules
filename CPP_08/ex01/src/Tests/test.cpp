/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:50:36 by iziane            #+#    #+#             */
/*   Updated: 2024/12/21 22:26:28 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Tests/test.hpp"
#include "Span.hpp"
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
} // namespace testrunnner
