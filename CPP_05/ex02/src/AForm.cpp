/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:39:18 by iziane            #+#    #+#             */
/*   Updated: 2024/12/07 21:39:19 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Form.hpp"
#include "../Includes/AForm.hpp"

//OCF--BEGIN
AForm::AForm(void)
	: _name(DEFAULT_NAME_F), _signed(false), _signGrade(DEFAULT_GRADE_F), _executeGrade(DEFAULT_GRADE_F)
{
	printer::ocf_printer("AForm", printer::OCF_TYPE::DC);
}

AForm::AForm(const std::string& InputName, size_t InputSignGrade, size_t InputExecGrade)
	: _name(InputName), _signed(false), _signGrade(InputSignGrade), _executeGrade(InputExecGrade)
{
	if (InputSignGrade < MAX_GRADE_F || InputExecGrade < MAX_GRADE_F)
		throw (AForm::GradeTooHighException());
	if (InputSignGrade > MIN_GRADE_F || InputExecGrade > MIN_GRADE_F)
		throw (AForm::GradeTooLowException());
	printer::ocf_printer("AForm", printer::OCF_TYPE::DNC);
}

AForm::AForm(const AForm &og)
	: _name(og._name),
	_signed(og._signed),
	_signGrade(og._signGrade),
	_executeGrade(og._executeGrade)
{
	printer::ocf_printer("AForm", printer::OCF_TYPE::CC);
}

AForm &AForm::operator=(const AForm &og)
{
	if (this != &og)
	{
		printer::ocf_printer("AForm", printer::OCF_TYPE::CAC);
		_signed = og._signed;
	}
	return (*this);
}

AForm::~AForm(void)
{
	printer::ocf_printer("AForm", printer::OCF_TYPE::D);
}
//OCF--END

//Exceptions--BEGIN
const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too High !");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too Low !");
}

const char *AForm::AlreadySignedException::what() const throw()
{
	return ("AForm has already been signed !");
}

const char *AForm::NotSignedException::what() const throw()
{
	return ("AForm cannot be executed, it has not been signed yet!");
}

//Exceptions--END

//Members--BEGIN

/*
	1. chages Aform status to signed (bool signed) if ...
	2. Bureaucrates grade is higher or equal to required one --> if grade too low = AForm::GradeTooLowExeception
*/
void	AForm::beSigned(const Bureaucrat &og)
{
	if (this->getSignedStatus() == true)
	{
		// std::cout << *this;
		throw (AForm::AlreadySignedException());
	}
	if (og.getGrade() <= this->_signGrade)
	{
		this->_signed = true;
		// std::cout << og.getName() << " signed " << this->getName() << "\n";
	}
	else
	{
		// std::cout << og.getName() << " couldn't sign < " << this->getName()
			// << " because " << "his grade is too low" << "\n";
		throw (AForm::GradeTooLowException());
	}
}

//Getters--BEGIN
const std::string&	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getSignedStatus(void) const
{
	return (this->_signed);
}

size_t	AForm::getSignGrade(void) const
{
	return (this->_signGrade);
}

size_t	AForm::getExecGrade(void) const
{
	return (this->_executeGrade);
}
//Getters--END

std::ostream& operator<<(std::ostream& os, const AForm& og)
{
	os << "AForm " << og.getName() << " (";
	if (og.getSignedStatus() == true)
		os << "signed)";
	else
		os << "not signed)";
	os << ", Sign Grade " << og.getSignGrade() \
		<< ", Execution Grade " << og.getExecGrade() << ".\n";
	return (os);
}

void AForm::checkBureaucrat(Bureaucrat const & executor) const
{
	if (!(this->_signed))
		throw (AForm::NotSignedException());
	if (executor.getGrade() > this->getExecGrade())
		throw(AForm::GradeTooLowException());
}

