/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:50:36 by iziane            #+#    #+#             */
/*   Updated: 2024/12/14 21:12:05 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

//IMPLEMENTATION
namespace testrunner
{
	void randomGenerator(void)
	{
		size_t	x;
		size_t	c1 = 0;
		size_t	c2 = 0;
		size_t	c3 = 0;

		for (int i = 0; i < 90000; i++)
		{
			x = 1 + static_cast<unsigned int>(std::rand()) / ((RAND_MAX + 1u) / 3);
			if (x == 1){c1++;}
			else if (x == 2){c2++;}
			else if (x == 3){c3++;}
			std::cout << "x: " << x << "\n";
			// Note: 1 + rand() % sides is biased
		}
		std::cout << "Amoun of 1: " << c1 << "\n";
		std::cout << "Amoun of 2: " << c2 << "\n";
		std::cout << "Amoun of 3: " << c3 << "\n";
	}
} // namespace testrunnner
