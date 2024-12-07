/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:39:37 by iziane            #+#    #+#             */
/*   Updated: 2024/12/07 21:39:38 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

//Includes
#include "../Includes/AForm.hpp"
#include <fstream>
#include <iostream>


//Class

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	public:
	//OCF
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm &og);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &og);
		~ShrubberyCreationForm(void);
	//Members
		void execute(Bureaucrat const & executor) const override;
		std::string	getTarget(void) const;
};
