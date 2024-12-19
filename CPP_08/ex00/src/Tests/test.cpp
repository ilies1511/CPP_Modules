/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:50:36 by iziane            #+#    #+#             */
/*   Updated: 2024/12/19 22:44:09 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Tests/test.hpp"
// #include "test.hpp"

//IMPLEMENTATION
namespace testrunner
{
	void	ex00(void)
	{
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
	}
} // namespace testrunnner
