#ifndef FORM_HPP
# define FORM_HPP

//Includes
#include <stdbool.h>
#include "Bureaucrat.hpp"

//Class

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_executeGrade;
	//OCF
	public:
		Form(void);
		Form(const std::string& InputName, int InputSignGrade, int InputExecGrade);
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
	//Members
	public:
		void beSigned(const Bureaucrat &og);
};

std::ostream& operator<<(std::ostream& os, const Form& og);


#endif
