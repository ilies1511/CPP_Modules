/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_06.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:50:36 by iziane            #+#    #+#             */
/*   Updated: 2024/12/12 19:17:20 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_06.hpp"
#include "test_TypeDetection.hpp"

//IMPLEMENTATION
namespace testrunner
{
	void	TypeDetectionTest(void)
	{
		testTypeDetection::checkChar();
		testTypeDetection::checkInt();
		testTypeDetection::checkFloat();
		testTypeDetection::checkDouble();
		testTypeDetection::checkPseudoLiteral();
		testTypeDetection::checkMo();
	}
	void	interactive(void)
	{
		std::string line;
		std::string	action;

		std::system("clear");
		printer::Header("TESTRUNNER");
		while (true)
		{
			if (std::cin.eof() || action == "quit")
			{
				std::system("clear");
				return ;
			}
			if (action == "clear")
				std::system("clear");
			std::cout << "Enter element <clear, quit>: ";
			std::getline(std::cin, line);
			std::stringstream ss(line);
			ss >> action;
			ScalarConverte::convert(action);
		}
	}
} // namespace testrunnner
