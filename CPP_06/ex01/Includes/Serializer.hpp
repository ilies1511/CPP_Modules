#pragma once

//Includes
#include "Data.hpp"
#include "printer.hpp"

//Class
class Serializer
{
	// OCF - Deaktiviert, da Instanzierung nicht erlaubt
	private:
		Serializer(void) = delete;
		Serializer(const Serializer &og) = delete;
		Serializer operator=(const Serializer &og) = delete;
		~Serializer(void) = delete;
	//Memebers
	public:
		/*
			takes a pointer and converts it to the unsigned integer type
			uintptr_t
		*/
		static uintptr_t serialize(Data* ptr);
		/*
			takes an unsigned integer parameter and converts it to a pointer
			to Data
		*/
		static Data* deserialize(uintptr_t raw);
};

// std::ostream& operator<<(std::ostream &os, const Data *og);
