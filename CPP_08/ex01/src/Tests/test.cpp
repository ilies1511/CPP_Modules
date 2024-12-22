/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:50:36 by iziane            #+#    #+#             */
/*   Updated: 2024/12/22 01:30:57 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Tests/test.hpp"
#include "Span.hpp"
#include <random>
#include <ctime>
#include <string>

// #include "test.hpp"

//Helper --BEGIN
static void	dataGenerator(std::vector<int> &vecFiller)
{
	srand(static_cast<unsigned int>(time(NULL)));
	for (size_t i = 0; i < vecFiller.capacity(); i++)
	{
		vecFiller[i] = rand() % std::numeric_limits<int>::max() - 1;
	}
}

static void	printSpan(const Span &sp)
{
	for (size_t i = 0; i < sp.getSize(); i++)
	{
		std::cout << sp[i];
		if (i < sp.getSize() - 1)
			std::cout << ", ";
	}
	std::cout << "\n";
}
//Helper --END

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
			dataGenerator(vecFiller);
			sp.addRange(vecFiller.begin(), vecFiller.end());
			printSpan(sp);
		}
		catch(const std::exception& e)
		{
			printer::LogException(e, __FILE__, __FUNCTION__, __LINE__);
		}
	}

	void	edgeTests(void)
	{
		printer::Header("\nShould throw Exception: Container full");
		try
		{
			Span sp(1);
			sp.addNumber(6);
			sp.addNumber(-12);
		}
		catch(const std::exception& e)
		{
			printer::LogException(e, __FILE__, __FUNCTION__, __LINE__);
		}
		printer::Header("\nShould throw Exception: Out of Bound");
		try
		{
			Span sp(10);
			std::cout << sp[1] << "\n"; // this->_numbers.size() still 0
			// std::cout << sp[100] << "\n";
		}
		catch(const std::exception& e)
		{
			printer::LogException(e, __FILE__, __FUNCTION__, __LINE__);
		}
		printer::Header("\nShould throw Exception: Out of Bound");
		try
		{
			Span sp(10);
			std::cout << sp[100] << "\n";
		}
		catch(const std::exception& e)
		{
			printer::LogException(e, __FILE__, __FUNCTION__, __LINE__);
		}
		printer::Header("\nShould throw Exception: Container size is too small to add the range");
		try
		{
			Span sp(10);
			std::vector<int> vecFiller(100);
			dataGenerator(vecFiller);
			sp.addRange(vecFiller.begin(), vecFiller.end());
			printSpan(sp);
		}
		catch(const std::exception& e)
		{
			printer::LogException(e, __FILE__, __FUNCTION__, __LINE__);
		}
	}
} // namespace testrunnner
