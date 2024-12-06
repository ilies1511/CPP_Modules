/*
 * Imagine your program is like a factory producing widgets.
 *
 * - The `try` block is your production line where things can go wrong.
 *   It’s where you assemble widgets, but sometimes, parts may be faulty.
 *
 * - The `throw` keyword is like a loud alarm that signals something went wrong.
 *   When a problem occurs on the production line, the system "throws" an alert
 *   and halts the current process to prevent further damage.
 *
 * - The `catch` block is your emergency response team standing by to fix the issue.
 *   When the alarm is triggered, the `catch` block "catches" the problem, assesses it,
 *   and handles it appropriately (e.g., logs the error, fixes the widget, or stops production).
 *
 * Example flow:
 * 1. Code in the `try` block starts running (e.g., assembling widgets).
 * 2. If an error is detected, a `throw` triggers an alert with specific information
 *    (e.g., "Faulty widget detected!").
 * 3. The program immediately jumps to the matching `catch` block that can handle
 *    the type of error thrown (e.g., "Fixing the faulty widget").
 * 4. Once handled, the program continues safely without crashing.
 *
 * Using this system, we ensure that errors don’t cause the entire factory (program)
 * to collapse but instead allow for safe and controlled recovery.
 */

// #include "Bureaucrat.hpp"
#include "../Includes/Bureaucrat.hpp"
// #include "Form.hpp"
#include "../Includes/AForm.hpp"

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
	else if (InputGrade > MIN_GRADE)
	{
		this->_grade = MIN_GRADE;
		throw Bureaucrat::GradeTooLowException();
		// throw Bureaucrat::GradeTooLowException::exception(); --> TODO: welche Version
	}
	// printer::ocf_printer("Bureaucrat", printer::OCF_TYPE::DNC);
	std::cout << coloring("[Bureaucrat]: InputGrade Constructor called\n", BROWN);
}

// Default Name Constructor
Bureaucrat::Bureaucrat(const std::string& InputName)
	: _name(InputName), _grade(DEFAULT_GRADE)
{
	printer::ocf_printer("Bureaucrat", printer::OCF_TYPE::DNC);
}

// Default Input Constructor
Bureaucrat::Bureaucrat(size_t InputGrade, const std::string& InputName)
	: _name(InputName), _grade(InputGrade)
{
	if (InputGrade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	if (InputGrade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
		// throw Bureaucrat::GradeTooLowException::exception(); --> TODO: welche Version
	// printer::ocf_printer("Bureaucrat", printer::OCF_TYPE::DNC);
	std::cout << coloring("[Bureaucrat]: *Input Constructor called\n", BROWN);
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
	return ("Grade too High !");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too Low !");
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
	if (this->_grade <= MAX_GRADE)
		throw (Bureaucrat::GradeTooHighException());
	this->_grade--;
}

void Bureaucrat::decrementGrade(void) //decrementing a grade 3 should give a grade 4
{
	if (this->_grade >= MIN_GRADE)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade++;
}

// Muster: <name>, bureaucrat grade <grade>.
std::ostream& operator<<(std::ostream& os, const Bureaucrat& og)
{
	os << og.getName() << ", bureaucrat grade " << og.getGrade() << ".\n";
	return (os);
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << "\n";
	}
	catch (std::exception &e)
	{
		std::cerr << this->getName() << " couldn't sign " << form.getName() \
		<<  " because " << e.what() << "\n";
	}
}

