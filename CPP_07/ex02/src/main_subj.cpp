#include <Array.hpp>
#include <iostream>
#include <ctime>
#include "test.hpp"

#define MAX_VAL 750

int	main(int, char **)
{
	int	*mirror;
		const int value = rand();

	Array<int> numbers(MAX_VAL);
	mirror = new int[MAX_VAL];
	// srand(time(NULL));
	srand(static_cast<unsigned int>(time(NULL)));
	for (size_t i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = value;
		mirror[i] = value;
	}
	// SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}
	for (size_t i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return (1);
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch (const std::exception &e)
	{
		printer::Header("Test with numbers[-2]");
		printer::LogException(e, __FILE__, __FUNCTION__, __LINE__);
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception &e)
	{
		printer::Header("Test with numbers[MAX_VAL]");
		printer::LogException(e, __FILE__, __FUNCTION__, __LINE__);
	}
	for (size_t i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete[] mirror; //
	return (0);
}
