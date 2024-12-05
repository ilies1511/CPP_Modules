// #include "Form.hpp"
#include "../Includes/Form.hpp"

//OCF--BEGIN
Form::Form(void)
	: _name(DEFAULT_NAME), _signed(false), _signGrade(DEFAULT_GRADE), _executeGrade(DEFAULT_GRADE)
{
	printer::ocf_printer("Form", printer::OCF_TYPE::DC);
}

Form::Form(const std::string& InputName, int InputSignGrade, int InputExecGrade)
	: _name(InputName), _signed(false), _signGrade(InputSignGrade), _executeGrade(InputExecGrade)
{
	if (InputSignGrade < MAX_GRADE || InputExecGrade < MAX_GRADE)
		throw (Form::GradeTooHighException());
	if (InputSignGrade > MIN_GRADE || InputExecGrade > MIN_GRADE)
		throw (Form::GradeTooLowException());
	printer::ocf_printer("Form", printer::OCF_TYPE::DNC);
}

Form::Form(const Form &og)
	: _name(og._name),
	_signed(og._signed),
	_signGrade(og._signGrade),
	_executeGrade(og._executeGrade)
{
	printer::ocf_printer("Form", printer::OCF_TYPE::CC);
}

Form &Form::operator=(const Form &og)
{
	if (this != &og)
	{
		printer::ocf_printer("Form", printer::OCF_TYPE::CAC);
		_signed = og._signed;
	}
	return (*this);
}

Form::~Form(void)
{
	printer::ocf_printer("Form", printer::OCF_TYPE::D);
}
//OCF--END

//Exceptions--BEGIN
const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too High !");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too Low !");
}

const char *Form::AlreadySignedException::what() const throw()
{
	return ("Form has already been signed !");
}

//Exceptions--END

//Members--BEGIN

/*
	1. chages form status to signed (bool signed) if ...
	2. Bureaucrates grade is higher or equal to required one --> if grade too low = Form::GradeTooLowExeception
*/
void	Form::beSigned(const Bureaucrat &og)
{
	if (this->getSignedStatus() == true)
	{
		std::cout << this;
		throw (Form::AlreadySignedException());
	}
	if (og.getGrade() <= this->_signGrade)
	{
		this->_signed = true;
		// std::cout << og.getName() << " signed " << this->getName() << "\n";
	}
	else
	{
		// std::cout << og.getName() << " couldn't sign < " << this->getName() \
			<< " because " << "his grade is too low" << "\n";
		throw (Form::GradeTooLowException());
	}
}

//Getters--BEGIN
const std::string&	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getSignedStatus(void) const
{
	return (this->_signed);
}

size_t	Form::getSignGrade(void) const
{
	return (this->_signGrade);
}

size_t	Form::getExecGrade(void) const
{
	return (this->_executeGrade);
}
//Getters--END

std::ostream& operator<<(std::ostream& os, const Form& og)
{
	os << "Form " << og.getName() << "(";
	if (og.getSignedStatus() == true)
		os << "signed) ";
	else
		os << "not signed) ";
	os << ", Sign Grade " << og.getSignGrade() \
		<< ", Execution Grade " << og.getExecGrade() << ".\n";
	return (os);
}
