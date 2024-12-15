/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_TypeDetection.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:45:32 by iziane            #+#    #+#             */
/*   Updated: 2024/12/15 14:45:33 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

//Imclude
#include <iostream>
#include <string>
#include "Extra/printer.hpp"
#include "TypeDetection.hpp"

namespace testTypeDetection
{
	void	checkWhat(const std::string& Type, const std::string& testInput, bool (*checkFunction)(const std::string&));
	void	checkPseudoLiteral(void);
	void	checkDouble(void);
	void	checkFloat(void);
	void	checkInt(void);
	void	checkChar(void);
	void	checkMo(void);
}



