/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_06.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:50:36 by iziane            #+#    #+#             */
/*   Updated: 2024/12/09 19:50:17 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/tests_06.hpp"
#include "../Includes/tests_06.hpp"
#include "test_TypeDetection.cpp"

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
		// //TODO:
	}
} // namespace testrunnner
