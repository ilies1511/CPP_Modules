#include "../Includes/PresidentialPardonForm.hpp"

//OFC--BEGIN
PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("PresidentialPardonForm", 25, 5), _target("root")
{
	printer::ocf_printer("PresidentialPardonForm", printer::OCF_TYPE::DC);
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	printer::ocf_printer("PresidentialPardonForm", printer::OCF_TYPE::DNC);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &og)
	: AForm(og), _target(og._target)
{
	printer::ocf_printer("PresidentialPardonForm", printer::OCF_TYPE::CC);
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &og)
{
	if (this != &og)
	{
		this->_target = og._target;
		printer::ocf_printer("PresidentialPardonForm", printer::OCF_TYPE::CAC);
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	printer::ocf_printer("PresidentialPardonForm", printer::OCF_TYPE::D);
}
//OFC--END

//Members--BEGIN
void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	checkBureaucrat(executor);
	std::cout << coloring(this->getTarget() + " has been pardoned by Zaphod Beeblebrox\n", GREEN);
}
//Members--END

//Getters--BEGIN
std::string	PresidentialPardonForm::getTarget(void) const
{
	return(this->_target);
}
//Getters--END

