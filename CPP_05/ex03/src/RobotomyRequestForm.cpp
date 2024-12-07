/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:33:38 by iziane            #+#    #+#             */
/*   Updated: 2024/12/07 21:33:38 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "RobotomyRequestForm.hpp"

//OFC--BEGIN
RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("RobotomyRequestForm", 72, 45), _target("root")
{
	printer::ocf_printer("RobotomyRequestForm", printer::OCF_TYPE::DC);
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	printer::ocf_printer("RobotomyRequestForm", printer::OCF_TYPE::DNC);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &og)
	: AForm(og), _target(og._target)
{
	printer::ocf_printer("RobotomyRequestForm", printer::OCF_TYPE::CC);
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &og)
{
	if (this != &og)
	{
		this->_target = og._target;
		printer::ocf_printer("RobotomyRequestForm", printer::OCF_TYPE::CAC);
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	printer::ocf_printer("RobotomyRequestForm", printer::OCF_TYPE::D);
}
//OFC--END

//Members--BEGIN
void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	checkBureaucrat(executor);
	std:: cout << "* drilling noices *\n";
	if (rand() % 2)
		std::cout << coloring(this->getTarget() + " has been robotomized successfully\n", GREEN);
	else
		std::cout << coloring(this->getTarget() + " robotomized failed\n", RED);
}
//Members--END

//Getters--BEGIN
std::string	RobotomyRequestForm::getTarget(void) const
{
	return(this->_target);
}
//Getters--END

