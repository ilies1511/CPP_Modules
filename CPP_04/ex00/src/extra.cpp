/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:47:45 by iziane            #+#    #+#             */
/*   Updated: 2024/11/15 16:41:12 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extra.hpp"

//Display
std::string coloring(const std::string text, const std::string &color)
{
	return (color + text + NC);
}
