/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_05.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:50:36 by iziane            #+#    #+#             */
/*   Updated: 2024/12/04 19:38:14 by iziane           ###   ########.fr       */
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
			std::cerr << "Caught GradeTooHighException: " << e.what() << std::endl;
		}
		catch (const Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "Caught GradeTooLowException: " << e.what() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
	}
	void	decrementGrade(void)
	{
		try
		{
			Bureaucrat	bebsi(150, "Seh'ween");
			std::cout << bebsi;
			bebsi.decrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	void	incrementGrade(void)
	{
		try
		{
			Bureaucrat	bebsi(3);

			for (size_t i = bebsi.getGrade(); i >= MAX_GRADE; i--)
			{
				std::cout << bebsi;
				bebsi.incrementGrade();
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
} // namespace testrunnner
