/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:21:12 by iziane            #+#    #+#             */
/*   Updated: 2024/12/22 18:21:15 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

/*
	Definition of Function Template
*/
template <typename T> typename T::iterator easyfind(T &container, int needle)
{
	typename T::iterator it = std::find(container.begin(), container.end(), // 'typename T::iterator it' same as 'auto it'
			needle);
	if (it == container.end())
		throw NotFoundException();
			// throw std::runtime_error("Value not found");
	return (it);
}
