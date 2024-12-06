/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_05.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:50:36 by iziane            #+#    #+#             */
/*   Updated: 2024/12/06 09:40:47 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/tests_05.hpp"

//IMPLEMENTATION
namespace testrunner05
{
	void	basic_ex01(void)
	{
		Form		paper;
		Bureaucrat	bebsi;

		Form	paper2(paper);
		paper.beSigned(bebsi);
		std::cout << paper;
		std::cout << paper2;

		bebsi.signForm(paper);
	}

	void	ex00(void)
	{
		basic_test();
		basic2_test();
		basic_plus_test();
		decrementGrade();
		incrementGrade();
		ocf_copyConstructor();
		ocf_copyAssignment();
	}

	void	basic_test(void)
	{
		printer::Header("BASIC TESTS");
		try
		{
			Bureaucrat bebsi(0);
		}
		catch (std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}
	void	basic2_test(void)
	{
		printer::Header("BASIC2 TESTS");
		try
		{
			Bureaucrat bebsi(151);
		}
		catch (std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}
	void	basic_plus_test(void)
	{
		printer::Header("BASIC_PLUS TESTS");
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
		printer::Header("DECREMENT TEST");
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
		printer::Header("INCREMENT TEST");
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
	void	ocf_copyConstructor(void)
	{
		printer::Header("CopyConstructor TEST");
		Bureaucrat bira(5, "Zizou");

		std::cout << bira;
		Bureaucrat biraHP(bira);
		biraHP.incrementGrade();
		std::cout << biraHP;
	}
	void	ocf_copyAssignment(void)
	{
		printer::Header("Copy Assignment TEST");
		Bureaucrat bira(55, "Zizou");

		std::cout << bira;
		Bureaucrat biraHP = bira;
		biraHP.incrementGrade();
		std::cout << biraHP;
	}
} // namespace testrunnner
