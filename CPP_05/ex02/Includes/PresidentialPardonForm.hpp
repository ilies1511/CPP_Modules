/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:39:42 by iziane            #+#    #+#             */
/*   Updated: 2024/12/07 21:39:43 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

//Includes
#include "../Includes/AForm.hpp"
#include <iostream>

//Class

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
	public:
	//OCF
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm &og);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &og);
		~PresidentialPardonForm(void);
	//Members
		void execute(Bureaucrat const & executor) const override;
		std::string	getTarget(void) const;
};
