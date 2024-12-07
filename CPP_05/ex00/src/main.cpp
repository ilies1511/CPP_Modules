/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:44:36 by iziane            #+#    #+#             */
/*   Updated: 2024/12/07 21:44:37 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_05.hpp"

int	main(void)
{
	testrunner05::basic_test();
	testrunner05::basic2_test();
	testrunner05::basic_plus_test();
	testrunner05::decrementGrade();
	testrunner05::incrementGrade();
	testrunner05::ocf_copyConstructor();
	testrunner05::ocf_copyAssignment();
	return (0);
}
