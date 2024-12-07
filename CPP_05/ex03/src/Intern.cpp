/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:33:57 by iziane            #+#    #+#             */
/*   Updated: 2024/12/07 21:33:59 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//OCF--BEGIN
Intern::Intern(void)
{
	printer::ocf_printer("Intern", printer::OCF_TYPE::DC);
}

Intern::Intern(const Intern &og)
{
	*this = og;
	printer::ocf_printer("Intern", printer::OCF_TYPE::CC);
}

Intern &Intern::operator=(const Intern &og)
{
	if (this != &og)
	{
		printer::ocf_printer("Intern", printer::OCF_TYPE::CAC);
		(void)og;
	}
	return (*this);
}

Intern::~Intern(void)
{
	printer::ocf_printer("Intern", printer::OCF_TYPE::D);
}
//OCF--END

//Members--BEGIN
AForm	*Intern::makeForm(const std::string &NameForm, const std::string &TargetOfForm)
{
	size_t	len;
	AForm* (Intern::*funcs[])(const std::string& target) = \
		{
			&Intern::createShrubberyForm,
			&Intern::createRobotomyRequestForm,
			&Intern::createPresidentialPardonForm
		};
	std::string Forms[] {"ShrubberyForm", "RobotomyForm", "PresidentialPardonForm"};
	len = sizeof(Forms) / sizeof(Forms[0]);
	int i = 0;
	for (; static_cast<unsigned long>(i) < len; i++)
	{
		if (!Forms[i].compare(NameForm))
		{
			std::cout << "Intern creates " << NameForm << "\n";
			return (this->*funcs[i])(TargetOfForm);
		}
	}
	std::cout << coloring("Form " + NameForm + " does not exist\n", RED);
	std::cout << coloring("[INFO]: Available Forms: ShrubberyForm, RobotomyForm, PresidentialPardonForm\n", BLUE);
	return (nullptr);
}

AForm *Intern::createShrubberyForm(const std::string &target)
{
	std::cout << "In ShrubberyForm\n";
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::createRobotomyRequestForm(const std::string &target)
{
	std::cout << "In RobotomyRequestForm\n";
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createPresidentialPardonForm(const std::string &target)
{
	std::cout << "In PresidentialPardonForm\n";
	return (new PresidentialPardonForm(target));
}

//Members--END

