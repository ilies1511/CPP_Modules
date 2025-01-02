/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:50:36 by iziane            #+#    #+#             */
/*   Updated: 2025/01/02 03:39:24 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Tests/test.hpp"
#include <vector>
#include "RPN.hpp"
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

	static void	test_flow(const std::string &teststring, ReversePolishNotation &rpn)
	{
		rpn.setString(teststring);
		rpn.processInput();
		std::cout << teststring << " ==> ";
		std::cout << coloring(std::to_string(rpn.getTop()) + "\n", GREEN);
	}

	static void	handle_try_catch(const std::string &teststring, ReversePolishNotation &rpn)
	{
		try
		{
			test_flow(teststring, rpn);
		}
		catch(const std::exception& e)
		{
			std::cout << "\n";
			printer::LogException(e, __FILE__, __FUNCTION__, __LINE__);
			std::cout << coloring("Test-String: \"" + teststring + "\"\n", RED);
		}
	}

	void	test_IST_SOLL(void)
	{
		/*
			"8 9 * 9 - 9 - 9 - 4 - 1 +" --> 42
			"7 7 * 7 -" --> 42
			"1 2 * 2 / 2 * 2 4 - +" --> 0
			"9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -" --> 42
			"1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /" --> 15
			"9 0 /" --> Exception
		*/
		ReversePolishNotation	rpn;

		const std::string tests[] = {
			"8 9 * 9 - 9 - 9 - 4 - 1 +",
			"7 7 * 7 -",
			"1 2 * 2 / 2 * 2 4 - +",
			"9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -",
			"1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /",
			"1 1 1 1 1 1 1 + + + + + +",
			"9 1 * 2 / 2 3 4 5 * 6 + - + * ",
			"  8   			9   *   9    -    9     -   9    -   4  -   1   +    ",
			"9 0 /",
			"9 1 * 2 / 0",
			"9 1 * 2 / 1 1 3"
		};
		for (size_t i = 0; i < (sizeof(tests) / sizeof(tests[0])) ; i++)
			handle_try_catch(tests[i], rpn);
	}
} // namespace testrunnner
