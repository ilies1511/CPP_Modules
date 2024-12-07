#pragma once

//Includes
#include <iostream>
#include <string>
#include "AForm.hpp"
//Class

class Intern
{
	private:
	//OCF
	public:
		Intern(void);
		Intern(const std::string InputName);
		Intern(const Intern &og);
		Intern &operator=(const Intern &og);
		~Intern(void);
	//Members
	public:
		AForm	*makeForm(const std::string NameForm, const std::string TargetOfForm);
};
