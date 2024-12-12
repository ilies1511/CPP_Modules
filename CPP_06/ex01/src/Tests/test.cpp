/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:50:36 by iziane            #+#    #+#             */
/*   Updated: 2024/12/12 21:40:05 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

//IMPLEMENTATION
namespace testrunner
{
	void	compare_addresses(void)
	{
		uintptr_t	serialized;
		Data		*deserializedData;
		printer::Header("TEST EX01");

		Data originalData{42, "Test Data"};

		//Adresse des Objekts serialisieren
		serialized = Serializer::serialize(&originalData);
		// 3. Serialisierten Wert deserialisieren
		deserializedData = Serializer::deserialize(serialized);
		// 4. Überprüfen, ob der Zeiger korrekt ist
		std::cout << "Original Data Address: " << &originalData << "\n";
		std::cout << "Deserialized Data Address: " << deserializedData << "\n";
		// 5. Daten vergleichen
		if (deserializedData == &originalData)
		{
			std::cout << coloring("Pointers match! Data successfully serialized and deserialized.\n", GREEN);
			std::cout << "ID: " << deserializedData->i << ", Name: " << deserializedData->str << "\n";
		}
		else
			std::cout << coloring("Pointers do not match. Serialization failed\n", RED);
	}
} // namespace testrunnner
