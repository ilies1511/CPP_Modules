/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_05.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:50:36 by iziane            #+#    #+#             */
/*   Updated: 2024/12/06 22:54:48 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/tests_05.hpp"

//IMPLEMENTATION
namespace testrunner05
{
	void	ex02(void)
	{
		basicTest_ShrubberyCreationForm();
		basicTest_RobotomyRequestForm();
		basicTest_PresidentialPardonForm();
	}
	void	basicTest_ShrubberyCreationForm(void)
	{
		printer::Header("\nTEST ShrubberyCreationForm");
		Bureaucrat				zaepfchen(146, "Zaepfchen"); //Cannot sign Form since grade too low
		Bureaucrat				zizou(1, "Zizou"); //Can sign Form since grade is 'greater' than sign=25 & exex=5 (greater in this context means lower)
		ShrubberyCreationForm	shrubberyForm;
		try
		{
			printer::Header("ZAEPFCHEN attempts to sign Form");
			zaepfchen.signForm(shrubberyForm);
			printer::Header("ZIOU attempts to sign Form");
			zizou.signForm(shrubberyForm);
			printer::Header("ZIOU attempts to sign Form AGAIN !");
			//Double Signings should be prevented
			zizou.signForm(shrubberyForm);
			printer::Header("ZIOU attempts to execute Form");
			// shrubberyForm.execute(zizou);
			zizou.executeForm(shrubberyForm);
			printer::Header("ZAEPFCHEN attempts to execute Form");
			// shrubberyForm.execute(zaepfchen);
			zaepfchen.executeForm(shrubberyForm);
		}
		catch(const std::exception& e)
		{
			std::cerr << "[Exception]: " << e.what() << '\n';
		}
	}
	void	basicTest_RobotomyRequestForm(void)
	{
		printer::Header("\nTEST RobotomyRequestForm");		Bureaucrat				zaepfchen(73, "Zaepfchen"); //Cannot sign Form since grade too low
		Bureaucrat				zizou(45, "Zizou"); //Can sign Form since grade is greater than sign=72 & exex=45 for robotForm
		RobotomyRequestForm		robotForm;
		try
		{
			printer::Header("ZAEPFCHEN attempts to sign Form");
			zaepfchen.signForm(robotForm);
			printer::Header("ZIOU attempts to sign Form");
			zizou.signForm(robotForm);
			printer::Header("ZIOU attempts to execute Form");
			// robotForm.execute(zizou);
			zizou.executeForm(robotForm);
			printer::Header("ZAEPFCHEN attempts to execute Form after 1/2 probable Booster");
			if (rand() % 2)
			{
				while (zaepfchen.getGrade() >= robotForm.getExecGrade())
					zaepfchen.incrementGrade();
			}
			// robotForm.execute(zaepfchen);
			zaepfchen.executeForm(robotForm);
		}
		catch(const std::exception& e)
		{
			std::cerr << "[Exception]: " << e.what() << '\n';
		}
	}
	void	basicTest_PresidentialPardonForm(void)
	{
		printer::Header("\nTEST PresidentialPardonForm");
		Bureaucrat				zaepfchen(26, "Zaepfchen"); //Cannot sign Form since grade too low
		Bureaucrat				zizou(5, "Zizou"); //Can sign Form since grade is greater than sign=25 & exex=5
		PresidentialPardonForm	presidentForm;
		try
		{
			printer::Header("ZAEPFCHEN attempts to sign Form");
			zaepfchen.signForm(presidentForm);
			printer::Header("ZIOU attempts to sign Form");
			zizou.signForm(presidentForm);
			printer::Header("ZIOU attempts to execute Form");
			// presidentForm.execute(zizou);
			zizou.executeForm(presidentForm);
			printer::Header("ZAEPFCHEN attempts to execute Form");
			// presidentForm.execute(zaepfchen);
			zaepfchen.executeForm(presidentForm);
		}
		catch(const std::exception& e)
		{
			std::cerr << "[Exception]: " << e.what() << '\n';
		}
	}
} // namespace testrunnner
