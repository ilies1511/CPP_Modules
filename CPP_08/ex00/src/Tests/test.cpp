/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:50:36 by iziane            #+#    #+#             */
/*   Updated: 2024/12/19 22:54:27 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Tests/test.hpp"
// #include "test.hpp"

//IMPLEMENTATION
namespace testrunner
{
	void	ex00(void)
	{
		printer::Header("TEST: Vector<int>");
		try
		{
			std::vector<int> numbers = {1, 2, 3, 4, 5};

			// std::vector<int>::iterator it = easyfind(numbers, -12);
			auto it = easyfind(numbers, -12);
			std::cout << "Found: " << *it << std::endl;
		}
		catch (const std::exception& e)
		{
			printer::LogException(e, __FILE__, __FUNCTION__, __LINE__);
		}
		printer::Header("\nTEST: Vector<int>");
		try
		{
			std::vector<int> numbers = {1, 2, 3, 4, 5};

			// std::vector<int>::iterator it = easyfind(numbers, -12);
			auto it = easyfind(numbers, 1);
			std::cout << coloring("Found: " + std::to_string(*it) + "\n", GREEN);
		}
		catch (const std::exception& e)
		{
			printer::LogException(e, __FILE__, __FUNCTION__, __LINE__);
		}
		printer::Header("\nTEST: Vector<char>");
		try
		{
			std::vector<char> numbers = {'1', '2', '3', '4', '5'};

			// std::vector<int>::iterator it = easyfind(numbers, -12);
			auto it = easyfind(numbers, '1');
			std::cout << coloring("Found: " + std::to_string(*it) + "\n", GREEN);
		}
		catch (const std::exception& e)
		{
			printer::LogException(e, __FILE__, __FUNCTION__, __LINE__);
		}
	}
} // namespace testrunnner
