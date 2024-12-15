/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:50:36 by iziane            #+#    #+#             */
/*   Updated: 2024/12/15 20:27:15 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../Includes/Tests/test.hpp"
#include "test.hpp"

//IMPLEMENTATION
namespace testrunner
{
	// Log	status;
	void	arrayXtemplate(void)
	{
		int		intArray[] = {99, 9, 92, 23, 232, 2};
		char	charArray[] = {'O','u', 'e', 'y', 'Z', 'i', 'z', 'o', 'u'};
		iter(intArray, sizeof(intArray) / sizeof(intArray[0]), printElement<int>);
		iter(charArray, sizeof(charArray) / sizeof(charArray[0]), printElement<char>);
	}
} // namespace testrunnner
