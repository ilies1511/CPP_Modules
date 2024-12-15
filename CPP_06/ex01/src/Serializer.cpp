/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:46:41 by iziane            #+#    #+#             */
/*   Updated: 2024/12/15 14:46:43 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

//Methodes--BEGIN

// takes a pointer and converts it to the unsigned integer type uintptr_t
uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

// takes an unsigned integer parameter and converts it to a pointer to Data
Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

// std::ostream& operator<<(std::ostream &os, const Data *og)
// {
// 	os << "Integer Value: " << og->i << "\nString Value: " << og->str;
// 	return (os);
// }

//Methodes--END

