#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("ShrubberyCreationForm", 145, 137), _target("root")
{
	printer::ocf_printer("ShrubberyCreationForm", printer::OCF_TYPE::DC);
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	printer::ocf_printer("ShrubberyCreationForm", printer::OCF_TYPE::DNC);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &og)
	: AForm(og), _target(og._target)
{
	printer::ocf_printer("ShrubberyCreationForm", printer::OCF_TYPE::CC);
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &og)
{
	if (this != &og)
	{
		this->_target = og._target;
		printer::ocf_printer("ShrubberyCreationForm", printer::OCF_TYPE::CAC);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	printer::ocf_printer("ShrubberyCreationForm", printer::OCF_TYPE::D);
}
