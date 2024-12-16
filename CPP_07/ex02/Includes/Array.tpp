/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 23:14:24 by iziane            #+#    #+#             */
/*   Updated: 2024/12/16 23:14:27 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

//Includes
#include "Array.hpp"

//						OCF--BEGIN
//Default Constructor
template<typename T>
Array<T>::Array(void) : _array(nullptr), _size(0)
{
	printer::ocf_printer("Array", printer::OCF_TYPE::DC);
}

//Input Constructor
template<typename T>
Array<T>::Array(size_t n) : _array(n > 0 ? new T[n] : nullptr), _size(n)
{
	printer::ocf_printer("Array", printer::OCF_TYPE::DNC);
}

//Copy Constructor
template<typename T>
Array<T>::Array(const Array &og) : _array(nullptr), _size(0)
{
	*this = og;
	printer::ocf_printer("Array", printer::OCF_TYPE::CC);
}

//Copy Assigment Constructor
template<typename T>
Array<T> &Array<T>::operator=(const Array &og)
{
	if (this != &og)
	{
		printer::ocf_printer("Array", printer::OCF_TYPE::CAC);
		T *newArray = new T[og._size]; // temp
		for (size_t i = 0; i < og._size; ++i)
		{
			newArray[i] = og._array[i];
		}
		delete[] _array;
		_array = newArray;
		_size = og._size;
	}
	return (*this);
}

//Destructor
template<typename T>
Array<T>::~Array(void)
{
	delete[] _array;
	printer::ocf_printer("Array", printer::OCF_TYPE::D);
}
//							OCF--END

//Methodes--BEGIN

template<typename T>
size_t	Array<T>::size(void) const
{
	return (this->_size);
}

//Overload '[]' Operator (write writes)
template<typename T>
T& Array<T>::operator[](size_t index)
{
	if (index >= this->_size)
		throw (OutOfBoundsException()); //TODO: Write own Exception
	return (this->_array[index]);
}

//Overload '[]' Operator (since const only read writes --> returned elements cannot be modified)
template<typename T>
const T& Array<T>::operator[](size_t index) const
{
	if (index >= this->_size)
		throw (OutOfBoundsException());
	return (this->_array[index]);
}

//Exception:
template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Index is out of bound !");
}

//printArray
template <typename T>
void	Array<T>::printArray(void)
{
	if (this->_size == 0 || _array == nullptr)
	{
		std::cout << "[INFO]: Array is empty !\n" << "File Name: " << __FILE__ << "\n" \
			<< "Function: " << __FUNCTION__ << "\n" << "Line: "<< __LINE__ << "\n";
		return ;
	}
	size_t i = 0;
	for (; i < _size; i++)
	{
		std::cout << this->_array[i];
		if (i < _size - 1)
			std::cout << ", ";
	}
	std::cout << std::endl;
}
//Methodes--END
