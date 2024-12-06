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

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const size_t		_signGrade;
		const size_t		_executeGrade;
	//OCF
	public:
		Form(void);
		Form(const std::string& InputName, size_t InputSignGrade, size_t InputExecGrade);
		Form(const Form &og);
		Form &operator=(const Form &og);
		~Form(void);
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
	//Members
	public:
		void				beSigned(const Bureaucrat &og);
		//getters
		const std::string&	getName(void) const;
		bool				getSignedStatus(void) const;
		size_t				getSignGrade(void) const;
		size_t				getExecGrade(void) const;
};

std::ostream& operator<<(std::ostream& os, const Form& og);
