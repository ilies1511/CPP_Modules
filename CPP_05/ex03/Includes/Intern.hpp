#pragma once

//Includes
#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

//Class

class Intern
{
	private:
		AForm	*createShrubberyForm(const std::string &target);
		AForm	*createRobotomyRequestForm(const std::string &target);
		AForm	*createPresidentialPardonForm(const std::string &target);
	//OCF
	public:
		Intern(void);
		Intern(const Intern &og);
		Intern &operator=(const Intern &og);
		~Intern(void);
	//Members
	public:
		/*
			ARGS:
				First arg: name of a form a,
				Second arg: target of the form
			Return Value:
				Pointer to Form object (whose name is passed as param => first param)
				That Form Object will initialized its target with second param
		*/
		AForm	*makeForm(const std::string &NameForm, const std::string &TargetOfForm);
};
