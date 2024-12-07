/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:34:19 by iziane            #+#    #+#             */
/*   Updated: 2024/12/07 21:34:20 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
