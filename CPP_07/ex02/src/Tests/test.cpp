#include "../Includes/Tests/test.hpp"
#include "test.hpp"
#include <Array.hpp>
#include <ctime>

#define MAX_VAL 750

//IMPLEMENTATION
namespace testrunner
{
	int	subj_TEST(void)
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

	void	ownDataType(void)
	{
		struct Data
		{
			int32_t		i; // 4-bytes
			std::string	str;
		};

		Array<Data> ownDataType(2);
		ownDataType[0] = {1, "Ouey"};
		ownDataType[1] = {0, "Zizou"};
		for (size_t i = 0; i < 2; i++)
		{
			try
			{
				std::cout << "i: " << ownDataType[i].i \
				<< ", str: " << ownDataType[i].str << "\n";
			}
			catch (std::exception &e)
			{
				printer::LogException(e, __FILE__, __FUNCTION__, __LINE__);
				return ;
			}
		}
	}

	void	stringArray(void)
	{
		Array<std::string> prettyNameBook(6);
		printer::Header("printArray with emptyArray");

		prettyNameBook[0] = "Seh'ween";
		prettyNameBook[1] = "Damian";
		prettyNameBook[2] = "Gwyneth";
		prettyNameBook[3] = "Walter";
		prettyNameBook[4] = "Justin-Rene";
		prettyNameBook[5] = "Patrice";
		printer::Header("[printArray]: prettyNameBook[]");
		prettyNameBook.printArray();
		printer::Header("[Exception TEST]: prettyNameBook");
		try
		{
			prettyNameBook[13131];
		}
		catch(const std::exception& e)
		{
			printer::Header("Test with prettyNameBook[13131]");
			printer::LogException(e, __FILE__, __FUNCTION__, __LINE__);
		}
	}

	void	emptyArray(void)
	{
		Array<int> emptyArray;
		printer::Header("[printArray]: alo[]");
		emptyArray.printArray();
	}

	void	allocation(void)
	{
		Array<int> *heapArray = new Array<int>(5);
		for (size_t i = 0; i < heapArray->size(); ++i)
		{
			(*heapArray)[i] = static_cast<int>(i * 10); // Populate with values 0, 10, 20, ...
		}
		printer::Header("Print heapArray[]");
		heapArray->printArray();
		delete heapArray;
	}

} // namespace testrunnner
