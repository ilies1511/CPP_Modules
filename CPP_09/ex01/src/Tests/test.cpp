/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:50:36 by iziane            #+#    #+#             */
/*   Updated: 2024/12/30 23:31:18 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Tests/test.hpp"
// #include "test.hpp"

//IMPLEMENTATION
namespace testrunner
{
	void	test_printStack(void)
	{
		printer::Header("TEST: test_printStack()");
		ReversePolishNotation	rpn;

		rpn.pushDigit(1);
		rpn.pushDigit(2);
		rpn.pushDigit(3);
		rpn.pushDigit(4);
		rpn.pushDigit(5);
		rpn.printStack();
	}

	void	test_IST_SOLL(void)
	{
		/*
			"8 9 * 9 - 9 - 9 - 4 - 1 +" --> 42
			"7 7 * 7 -" --> 42
			"1 2 * 2 / 2 * 2 4 - +" --> 0
			"9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -" --> 42
			"1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /" --> 15

		*/
		ReversePolishNotation	rpn;
		rpn.setString("8 9 * 9 - 9 - 9 - 4 - 1 +");
		rpn.processInput();
		std::cout << "8 9 * 9 - 9 - 9 - 4 - 1 +" << " ==> ";
		std::cout << coloring(std::to_string(rpn.getTop()) + "\n", GREEN);

		rpn.setString("7 7 * 7 -");
		rpn.processInput();
		std::cout << "7 7 * 7 -" << " ==> ";
		std::cout << coloring(std::to_string(rpn.getTop()) + "\n", GREEN);

		rpn.setString("1 2 * 2 / 2 * 2 4 - +");
		rpn.processInput();
		std::cout << "1 2 * 2 / 2 * 2 4 - +" << " ==> ";
		std::cout << coloring(std::to_string(rpn.getTop()) + "\n", GREEN);

		rpn.setString("9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -");
		rpn.processInput();
		std::cout << "9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -" << " ==> ";
		std::cout << coloring(std::to_string(rpn.getTop()) + "\n", GREEN);

		rpn.setString("1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /");
		rpn.processInput();
		std::cout << "1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /" << " ==> ";
		std::cout << coloring(std::to_string(rpn.getTop()) + "\n", GREEN);
	}
} // namespace testrunnner
