/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 23:13:50 by iziane            #+#    #+#             */
/*   Updated: 2024/12/16 23:13:50 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/*
	swap: Swaps the values of two given arguments. Does not return anything.
*/
template<typename T>
void swap(T &variable1, T &variable2)
{
	T	temp;

	temp = variable1;
	variable1 = variable2;
	variable2 = temp;
	return ;
}

/*
	min: Compares the two values passed in its arguments and returns the
	smallest one. If the two of them are equal, then it returns the second one.
*/
template<typename T>
T min(const T &variable1, const T &variable2)
{
	return ((variable2 <= variable1) ? variable2 : variable1);
}

/*
	max: Compares the two values passed in its arguments and returns the
	greatest one. If the two of them are equal, then it returns the second one.
*/
template<typename T>
T max(const T &variable1, const T &variable2)
{
	return ((variable2 >= variable1) ? variable2 : variable1);
}

