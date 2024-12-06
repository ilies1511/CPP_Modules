#pragma once

//Includes
#include "../Includes/AForm.hpp"
#include <cstdlib>
#include <ctime>

//Class
class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
	//OCF
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm &og);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &og);
		~RobotomyRequestForm(void);
	//Members
		void execute(Bureaucrat const & executor) const override;
		std::string	getTarget(void) const;
};
