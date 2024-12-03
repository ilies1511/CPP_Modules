#include "Bureaucrat.hpp"
//TODO: ADD ocf printer for interactive type --> Input Grade Constructor


//Default Constructor
Bureaucrat::Bureaucrat(void)
	: _name(DEFAULT_NAME), _grade(DEFAULT_GRADE)
{
	printer::ocf_printer("Bureaucrat", printer::OCF_TYPE::DC);
}

// Default InputGrade Constructor
Bureaucrat::Bureaucrat(size_t InputGrade)
	: _name(DEFAULT_NAME), _grade(InputGrade)
{
	if (InputGrade < MAX_GRADE)
	{
		this->_grade = MAX_GRADE; //Damit der Rest weiterlaufen kann
		throw Bureaucrat::GradeTooHighException();
	}
	else if (InputGrade < MIN_GRADE)
	{
		this->_grade = MIN_GRADE;
		throw Bureaucrat::GradeTooLowException();
		// throw Bureaucrat::GradeTooLowException::exception(); --> TODO: welche Version
	}
	printer::ocf_printer("Bureaucrat", printer::OCF_TYPE::DNC);
}

// Default Name Constructor
Bureaucrat::Bureaucrat(const std::string& InputName)
	: _name(InputName), _grade(DEFAULT_GRADE)
{
	printer::ocf_printer("Bureaucrat", printer::OCF_TYPE::DNC);
}

// Default Input Constructor
Bureaucrat::Bureaucrat(size_t InputGrade = MIN_GRADE, const std::string& InputName = "DefaultName")
	: _name(DEFAULT_NAME), _grade(DEFAULT_GRADE)
{
	printer::ocf_printer("Bureaucrat", printer::OCF_TYPE::DNC);
}

//Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat &og)
	: _name(og.getName()), _grade(og.getGrade())
{
	printer::ocf_printer("Bureaucrat", printer::OCF_TYPE::CC);
}

//Copy Assignment Constructor
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &og)
{
	if (this != &og)
		this->_grade = og._grade;
	printer::ocf_printer("Bureaucrat", printer::OCF_TYPE::CAC);
	return (*this);
}

//Destructor
Bureaucrat::~Bureaucrat(void)
{
	printer::ocf_printer("Bureaucrat", printer::OCF_TYPE::D);
}

// Exceptions
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("[Exception]: Grade too High !\n");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("[Exception]: Grade too Low !\n");
}

//Getter
const std::string& Bureaucrat::getName(void) const
{
	return (this->_name);
}

size_t Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade(void) //Grade = Grade - 1;
{
	if (this->_grade == MAX_GRADE)
		throw (Bureaucrat::GradeTooHighException());
	this->_grade--;
}

void Bureaucrat::decrementGrade(void) //decrementing a grade 3 should give a grade 4
{
	if (this->_grade == MIN_GRADE)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade++;
}

// Muster: <name>, bureaucrat grade <grade>.
std::ostream& operator<<(std::ostream& os, const Bureaucrat& og)
{
	os << og.getName() << ", bureaucrat grade " << og.getGrade() << ".\n";
	return (os);
}

