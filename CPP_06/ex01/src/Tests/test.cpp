/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:50:36 by iziane            #+#    #+#             */
/*   Updated: 2024/12/14 20:02:26 by iziane           ###   ########.fr       */
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

		printer::Header("[PRE-Serialization]: Size of originalData");
		std::cout << "Size of originalData: " << sizeof(originalData) << "\n";
		//values PRE Serialization
		printer::Header("[PRE-Serialization]: Values");
		std::cout << "Interger: " << originalData.i << "\nString: " \
			<< originalData.str << "\n";
		serialized = Serializer::serialize(&originalData);
		// 3. Serialisierten Wert deserialisieren
		deserializedData = Serializer::deserialize(serialized);
		printer::Header("[POST Deserialization]: Size of originalData");
		std::cout << "Size of deserializedData: " << sizeof(*deserializedData) << "\n";
		// check if Pointer is correct
		//Adresse des Objekts serialisieren
		std::cout << "Original Data Address: " << &originalData << "\n";
		std::cout << "Deserialized Data Address: " << deserializedData << "\n";
		// compare values
		if (deserializedData == &originalData)
		{
			std::cout << coloring("Pointers match! Data successfully serialized and deserialized.\n", GREEN);
		printer::Header("[POST-Deserialization]: Values");
			std::cout << "ID: " << deserializedData->i << ", Name: " << deserializedData->str << "\n";
		}
		else
			std::cout << coloring("Pointers do not match. Serialization failed\n", RED);
	}
} // namespace testrunnner
