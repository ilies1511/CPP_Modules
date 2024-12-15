/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:34:14 by iziane            #+#    #+#             */
/*   Updated: 2024/12/15 21:53:22 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

//Includes
#include "iostream"
#include "string"
#include <cstdlib>
#include <ctime>
//Mine
#include "printer.hpp"
#include "Log.hpp"

//Project
#include "iter.hpp"

typedef	struct s_data
{
	int32_t		i;
	std::string	name;
}				t_data;

namespace testrunner
{
	void	arrayXtemplate(void);
	void	ownDataType(void);
	void	adder(void);
}

