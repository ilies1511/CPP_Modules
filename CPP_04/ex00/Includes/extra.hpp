/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:45:13 by iziane            #+#    #+#             */
/*   Updated: 2024/11/21 09:45:14 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EXTRA_HPP
#define EXTRA_HPP


//Includes
#include <iostream>
#include <string>

// ANSI Escape Codes
const std::string GREEN = "\033[0;32m";
const std::string RED = "\033[0;31m";
const std::string BLUE = "\033[0;34m";
const std::string BOLD = "\033[1m";
const std::string ORANGE = "\033[38;2;255;165;0m";
const std::string PURPLE = "\033[38;2;128;0;128m";
const std::string NC = "\033[0m"; // Zurücksetzen

//FNC-Prototyp
	/*
		Usage:
			std::cout << coloring("Dieser Text ist grün!", GREEN) << std::endl;
	*/
	std::string coloring(const std::string text, const std::string &color);

#endif
