#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

//Includes
#include "printer.hpp"

//Macros
constexpr size_t MAX_GRADE = 1;
constexpr size_t MIN_GRADE = 150;

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
		Bureaucrat(size_t InputGrade = MIN_GRADE, const std::string& InputName = "DefaultName");
		Bureaucrat(const Bureaucrat &og);
		Bureaucrat &operator=(const Bureaucrat &og);
		~Bureaucrat(void);
	//Overloadin Operator
	public:
		Bureaucrat &operator++();
		Bureaucrat &operator--();
	//Methodes
	public:
		const std::string&	getName(void) const;
		size_t				getGrade(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);

};

std::ostream& operator<<(std::ostream& ostream, const Bureaucrat& og);

#endif
