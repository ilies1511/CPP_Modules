/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:44:45 by iziane            #+#    #+#             */
/*   Updated: 2024/12/07 21:44:46 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

//Includes
#include "printer.hpp"

//Macros
constexpr	size_t MAX_GRADE = 1;
constexpr	size_t MIN_GRADE = 150;
const		size_t DEFAULT_GRADE = MIN_GRADE;
const		std::string DEFAULT_NAME = "DefaultName";

//Class
class Bureaucrat
{
	private:
		const std::string	_name;
		size_t				_grade; //1 (highest possible grade) to 150 (lowest possible grade)
	//OCF
	public:
		Bureaucrat(void);
		Bureaucrat(size_t InputGrade);
		Bureaucrat(const std::string& InputName);
		Bureaucrat(size_t InputGrade, const std::string& InputName);
		Bureaucrat(const Bureaucrat &og);
		Bureaucrat &operator=(const Bureaucrat &og);
		~Bureaucrat(void);
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
	//Overloadin Operator
	// public:
	// 	Bureaucrat &operator++();
	// 	Bureaucrat &operator--();
	//Methodes
	public:
		const std::string&	getName(void) const;
		size_t				getGrade(void) const;
		void				incrementGrade(void); //incrementing a grade 3 should give a grade 2
		void				decrementGrade(void); //decrementing a grade 3 should give a grade 4
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& og);

#endif
