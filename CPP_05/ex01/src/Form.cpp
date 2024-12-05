#include "Form.hpp"

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
//Exceptions--END



