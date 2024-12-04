/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_05.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:50:36 by iziane            #+#    #+#             */
/*   Updated: 2024/12/04 19:04:02 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_05.hpp"

//IMPLEMENTATION
namespace testrunner05
{
	void	basic_test(void)
	{
		try
		{
			Bureaucrat bebsi(0);
		}
		catch (std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}
	void	basic_plus_test(void)
	{
		try
		{
			Bureaucrat bebsi(0);
		}
		catch (const Bureaucrat::GradeTooHighException &e)
		{
			std::cout << "Caught GradeTooHighException: " << e.what() << std::endl;
		}
		catch (const Bureaucrat::GradeTooLowException &e)
		{
			std::cout << "Caught GradeTooLowException: " << e.what() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}
} // namespace testrunnner
