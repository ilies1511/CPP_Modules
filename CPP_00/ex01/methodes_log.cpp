/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methodes.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:59:47 by iziane            #+#    #+#             */
/*   Updated: 2024/10/26 21:06:15 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

/*
	Methode-Definition of Log
*/
void Log::mf_set_level(Status level)
{
	m_loglevel = level;
}

void Log::mf_error(const std::string &msg)
{
	if (m_loglevel == ERROR)
		// std::cout << "[ERROR]: " << msg << '\n';
		std::cout << coloring("[ERROR]: " + msg, RED) << '\n';
}

void Log::mf_info(const std::string &msg)
{
	if (m_loglevel == INFO)
		std::cout << coloring("[INFO]: " + msg, BLUE) << '\n';
}

void	Log::print_log(Status status, const std::string &str)
{
	// Log			log;
	mf_set_level(status);
	mf_info(str);
}
