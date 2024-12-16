/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 23:14:02 by iziane            #+#    #+#             */
/*   Updated: 2024/12/16 23:14:06 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

//Includes
#include <cstddef>

//Template
template<typename T, typename FNC>
void iter(T *array, std::size_t length, FNC func)
{
	if (array == nullptr)
		return ;
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

//TestTemplates
template <typename T>
void printElement(const T& element)
{
	std::cout << element << std::endl;
}

template<typename T>
void	addOne(T &x)
{
	x += 1;
}
