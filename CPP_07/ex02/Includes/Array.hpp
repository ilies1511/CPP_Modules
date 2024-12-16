#pragma once

//Includes
#include <iostream>
#include <string>
#include "printer.hpp"

template<typename T>
class Array
{
	private:
		T		*_array; // Pointer to Array
		size_t	_size; // Amount of Elements in Array
	//OCF
	public:
		Array(void);
		Array(size_t n);
		Array(const Array &og);
		Array &operator=(const Array &og);
		~Array(void);
	//Methodes
	public:
		size_t	size(void) const;
	//Overload
	public:
		/*
			Overloeds '[]' operator in two ways:
				1. Returns reference from element --> enables its modification (write)
				2. Returns reference from element but CONST protect from modification --> enables its modification (only read)
		*/
		T& operator[](size_t index); //1
		const T& operator[](size_t index) const; //2
};
	/*
		Bedeutung der Const: const T& operator[](size_t index) const
			Erstes const:	Die zurückgegebene Referenz (const T&) ist konstant
							und kann nicht geändert werden.
			Zweites const:	Die Methode selbst darf keine Member-Variablen der
							Klasse ändern und kann deshalb auf const-Objekten
							aufgerufen werden.

	*/
#include "Array.tpp"
