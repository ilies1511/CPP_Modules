#include <fstream>
#include "ShrubberyCreationForm.hpp"

//OFC--BEGIN
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
//OFC--END

//Members--BEGIN
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	checkBureaucrat(executor);
	std::string filename;
	filename = this->_target + "_shrubbery";
	std::ofstream file(filename.c_str(), std::ios::out | std::ios::trunc);
	if (!file.is_open())
		std::cerr << "Failed opening/creating file " << filename;
	else
	{
		file << "\n"
			"                      * *                    \n"
			"                   *    *  *                \n"
			"              *  *    *     *  *            \n"
			"             *     *    *  *    *           \n"
			"         * *   *    *    *    *   *         \n"
			"         *     *  *    * * .#  *   *        \n"
			"         *   *     * #.  .# *   *           \n"
			"          *     \"#.  #: #\" * *    *       \n"
			"         *   * * \"#. ##\"       *          \n"
			"           *       \"###                       \n"
			"                     \"##                    \n"
			"                      ##.                    \n"
			"                      .##:                   \n"
			"                      :###                   \n"
			"                      ;###                   \n"
			"                    ,####.                   \n"
			"            /\\/\\/\\/\\/\\.######.\\/\\/\\/\\/\\ \n";
		file.close();
	}
}
//Members--END

//Getters--BEGIN
std::string	ShrubberyCreationForm::getTarget(void) const
{
	return(this->_target);
}
//Getters--END

