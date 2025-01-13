#include "DequePmergeMe.hpp"

//Sort -- BEGIN
int	cal_interPairSize(int recursion_level)
{
	return (static_cast<int>(std::pow(2, recursion_level - 1)));
}

void	go2nextXPair(typename std::deque<int>::iterator it, int interPairSize)
{
	std::advance(it, interPairSize);
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
	// /*
	// 	Init main-chain with {b1, a1};
	// */
	// main_chain.insert(main_chain.end(), next(_container.begin(), pair_level - 1)); // Inserte den Iterator in main_chain (Iterator zeigt gerade auf letztes Element des Paares) --> b1
	// main_chain.insert(main_chain.end(), next(_container.begin(), (pair_level * 2) - 1)); // Inserte den Iterator in main_chain (Iterator zeigt gerade auf letztes Element des Paares) --> a1

	// std::cout << "Print Main-Chain 1: \n";
	// this->printContainerHoldingIterators(main_chain);

	// //Do Rest
	// for (int i = 4; i <= pair_units_nbr; i += 2)
	// {
	// 	pend_chain.insert(pend_chain.end(), next(_container.begin(), pair_level * (i - 1) - 1));
	// 	main_chain.insert(main_chain.end(), next(_container.begin(), pair_level * i - 1));
	// }


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
		// printer::Header("Main-Chain");
		// this->printContainerHoldingIterators(main_chain);
		// printer::Header("Pend-Chain");
		// this->printContainerHoldingIterators(pend_chain);
	}
	while (pair_index <= pair_units_nbr);
	printer::Header("Main-Chain");
	this->printContainerHoldingIterators(main_chain);
	printer::Header("Pend-Chain");
	this->printContainerHoldingIterators(pend_chain);
}
