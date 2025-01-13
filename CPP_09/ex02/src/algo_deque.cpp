#include "DequePmergeMe.hpp"

//Sort -- BEGIN
int	cal_interPairSize(int recursion_level)
{
	return (static_cast<int>(std::pow(2, recursion_level - 1)));
}

void	DequePmergeMe::swap_pair(typename std::deque<int>::iterator it, int pair_level)
{
	Iterator	start;
	Iterator	end;

	start = next(it, -pair_level + 1);
	end = next(start, pair_level);
	while (start != end)
	{
		std::iter_swap(start, next(start, pair_level));
		++start;
	}
}

typename std::deque<int>::iterator next(typename std::deque<int>::iterator it, int steps)
{
	std::advance(it, steps);
	return (it);
}

template <typename T>
bool _comp(T lv, T rv)
{
	return (*lv < *rv);
}

void	DequePmergeMe::init_main_and_pendChain(std::deque<Iterator> &main_chain, std::deque<Iterator> &pend_chain, int &pair_level, int &pair_units_nbr)
{
	// std::deque<Iterator> main_chain;
	// std::deque<Iterator> pend_chain;

	// main_chain.insert(startpunkt, von (z.b Container a.begin), bis((z.b Container a.end))); --> Inserten einer Range ab Startpunkt
	// main_chain.insert(startpunkt, das_element); --> Inserten eines einzelnen Elements

	printer::Header("In Insertion Part");
	this->printContainer();

	printer::Header("Init MAIN -& PEND-CHAIN");
	int pair_index = 2; // Startindex für die Paare (entspricht 2. und 4. Element)
	do
	{
		if (pair_index == 2)
		{
			// Initialisierung der main_chain mit den ersten beiden Elementen (b1, a1)
			main_chain.insert(main_chain.end(), next(_container.begin(), pair_level - 1)); // b1
			main_chain.insert(main_chain.end(), next(_container.begin(), (pair_level * 2) - 1)); // a1
			// std::cout << "Print Main-Chain 1: \n";
		}
		else
		{
			pend_chain.insert(pend_chain.end(), next(_container.begin(), pair_level * (pair_index - 1) - 1));
			main_chain.insert(main_chain.end(), next(_container.begin(), pair_level * pair_index - 1));
		}
		pair_index += 2; // Erhöhe den Index um 2, um das nächste Paar zu verarbeiten
	}
	while (pair_index <= pair_units_nbr);
	printer::Header("Main-Chain");
	this->printContainerHoldingIterators(main_chain);
	printer::Header("Pend-Chain");
	this->printContainerHoldingIterators(pend_chain);
}

void	DequePmergeMe::entryPoint_Insertion(std::deque<Iterator> &main_chain, \
	std::deque<Iterator> &pend_chain, int &pair_level, int &pair_units_nbr, bool &is_odd, Iterator &very_last)
{
	init_main_and_pendChain(main_chain, pend_chain, pair_level, pair_units_nbr);
	jacobsthal_based_insertion(main_chain, pend_chain);
	sequential_based_insertion(main_chain, pend_chain);
	if (is_odd)
		odd_insertion(main_chain, very_last, pair_level);
}

void	DequePmergeMe::entryPoint_Merge(Iterator &start, Iterator &very_last, int &pair_level)
{
	int			next_pairs; //Steps to go until next pair
	Iterator	current_pair, next_pair;

	size_t i = 0;
	next_pairs = 2 * pair_level;
	for (Iterator it = start; it != very_last; std::advance(it, next_pairs), i++)
	{
		current_pair = next(it, pair_level - 1);
		next_pair = next(it, pair_level * 2 - 1);
		if (*current_pair > *next_pair)
		{
			swap_pair(current_pair, pair_level);
		}
	}
}

//ALGO-specific -- END
