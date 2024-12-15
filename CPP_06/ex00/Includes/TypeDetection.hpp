/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeDetection.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:45:40 by iziane            #+#    #+#             */
/*   Updated: 2024/12/15 14:45:42 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

//Includes
#include <iostream>
#include <string>
#include <regex>

bool	isPseudoLiteral(const std::string& literal);
bool	isChar(const std::string& literal);
bool	isInt(const std::string& literal);
bool	isFloat(const std::string& literal);
bool	isDouble(const std::string& literal);
