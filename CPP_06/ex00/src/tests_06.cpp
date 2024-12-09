/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_06.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:50:36 by iziane            #+#    #+#             */
/*   Updated: 2024/12/09 18:36:22 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/tests_06.hpp"

//IMPLEMENTATION
namespace testrunner
{
	// isChar: 'a', '~', ' ', ungültige Fälle: "ab", "9".
	static void	checkChar(void)
	{
		printer::Header("Test01");
		std::cout << "a: ";
		if (isChar("a"))
			std::cout << "Is Char\n";
		else
			std::cout << "No Char\n";

		printer::Header("Test02");
		std::cout << "ab: ";
		if (isChar("ab"))
		std::cout << "Is Char\n";
		else
			std::cout << "No Char\n";

		printer::Header("Test03");
		std::cout << "9: ";
		if (isChar("9"))
			std::cout << "Is Char\n";
		else
			std::cout << "No Char\n";
	}
	void	TypeDetectionTest(void)
	{
		checkChar();
		//TODO:
		checkInt();
		checkFloat();
		checkDouble();
	}
} // namespace testrunnner
