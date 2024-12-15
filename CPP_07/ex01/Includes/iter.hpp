#pragma once

//Includes
#include <cstddef>

//Template
template<typename T, typename FNC>
void iter(T *array, std::size_t length, FNC func)
{
	for (size_t i = 0; i < length; i++)
		func(array[i]);
	return ;
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
