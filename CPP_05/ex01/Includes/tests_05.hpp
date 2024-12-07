/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_05.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:41:35 by iziane            #+#    #+#             */
/*   Updated: 2024/12/07 21:41:36 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_05_HPP
# define TESTS_05_HPP

//Includes
#include "printer.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

namespace testrunner05
{
	//FUNC CALLS

	//ex00--BEGIN
	void	basic_test(void);
	void	basic2_test(void);
	void	basic_plus_test(void);
	void	decrementGrade(void);
	void	incrementGrade(void);
	void	ocf_copyConstructor(void);
	void	ocf_copyAssignment(void);
	void	ex00(void);
	//ex00--END

	//ex01--BEGIN
	void	ex01(void);
	void	basic_ex01(void);
	void	complex_ex01(void);
	//ex01--END
}

#endif

