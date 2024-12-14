/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:34:14 by iziane            #+#    #+#             */
/*   Updated: 2024/12/15 00:22:39 by iziane           ###   ########.fr       */
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

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

namespace testrunner
{
	void	randomGenerator(void);
	void	ex02(void);
	void	ex02_unregistered_subclass(void);
	void	ex02_Childs(void);
}

