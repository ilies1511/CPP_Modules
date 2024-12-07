/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:34:31 by iziane            #+#    #+#             */
/*   Updated: 2024/12/07 21:34:32 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
//Includes
#include <stdbool.h>
#include "Bureaucrat.hpp"

//Consts
constexpr	size_t MAX_GRADE_F = 1;
constexpr	size_t MIN_GRADE_F = 150;
const		size_t DEFAULT_GRADE_F = MIN_GRADE_F;
const		std::string DEFAULT_NAME_F = "DefaultForm";

//Class

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const size_t		_signGrade;
		const size_t		_executeGrade;
	//OCF
	public:
		AForm(void);
		AForm(const std::string& InputName, size_t InputSignGrade, size_t InputExecGrade);
		AForm(const AForm &og);
		AForm &operator=(const AForm &og);
		virtual ~AForm(void);
	//Exception
	public:
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class AlreadySignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class NotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
	//Members
	public:
		void				beSigned(const Bureaucrat &og);
		//getters
		const std::string&	getName(void) const;
		bool				getSignedStatus(void) const;
		size_t				getSignGrade(void) const;
		size_t				getExecGrade(void) const;
		virtual void		execute(Bureaucrat const & executor) const = 0;
	protected:
		void				checkBureaucrat(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& os, const AForm& og);
