/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:39:08 by iziane            #+#    #+#             */
/*   Updated: 2024/12/07 21:39:09 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/tests_05.hpp"

int	main(void)
{
	printer::Header("TESTS EX02");

	srand(static_cast<unsigned>(time(nullptr)));

	//ALL
	testrunner05::ex02();

	//Individual
	// testrunner05::basicTest_ShrubberyCreationForm();
	// testrunner05::basicTest_RobotomyRequestForm();
	// testrunner05::basicTest_PresidentialPardonForm();
	return (0);
}
