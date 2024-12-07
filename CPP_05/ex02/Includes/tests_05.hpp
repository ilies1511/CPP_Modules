/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_05.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:39:35 by iziane            #+#    #+#             */
/*   Updated: 2024/12/07 21:39:36 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_05_HPP
# define TESTS_05_HPP

//Includes
#include "printer.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

namespace testrunner05
{
	//FUNC CALLS
	//ex02--BEGIN
	void	ex02(void);
	void	basicTest_ShrubberyCreationForm(void);
	void	basicTest_RobotomyRequestForm(void);
	void	basicTest_PresidentialPardonForm(void);
	//ex02--END
}

#endif

