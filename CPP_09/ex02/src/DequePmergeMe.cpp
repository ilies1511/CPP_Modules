#include "DequePmergeMe.hpp"

//OCF -- BEGIN
DequePmergeMe::DequePmergeMe(int argc, char **argv) : PmergeMe(argc, argv)
{
	printer::ocf_printer("DequePmergeMe", printer::OCF_TYPE::DC);
}

DequePmergeMe::DequePmergeMe(const DequePmergeMe &og) : PmergeMe(og)
{
	printer::ocf_printer("DequePmergeMe", printer::OCF_TYPE::CC);
}

DequePmergeMe &DequePmergeMe::operator=(const DequePmergeMe &og)
{
	if (this != &og)
	{
		printer::ocf_printer("DequePmergeMe", printer::OCF_TYPE::CAC);
		PmergeMe::operator=(og);
	}
	return (*this);
}

DequePmergeMe::~DequePmergeMe(void)
{
	printer::ocf_printer("DequePmergeMe", printer::OCF_TYPE::D);
}
//OCF -- END


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


void DequePmergeMe::sort(void)
{
	int			pair_units_nbr; //Amount of Pairs
	bool		is_odd;
	// int			interPairSize;
	int			next_pairs; //Steps to go until next pair
	Iterator	start, last, very_last, current_pair, next_pair;
	int			pair_level;
	static int	recursion_level = 1; //TODO: add as private attribute in PmergeMe ?

	pair_level = cal_interPairSize(recursion_level++);
	is_odd = false;
	pair_units_nbr = static_cast<int>(_container.size()) / pair_level; //Break condition

	if (pair_units_nbr < 2)
		return ;

	std::cout << "Pair Level: " << pair_level << "\n";

	is_odd = pair_units_nbr % 2 == 1;

	start = _container.begin();
	last = next(_container.begin(), pair_level * (pair_units_nbr));
	very_last = next(last, -(is_odd * pair_level));

	size_t i = 0;
	next_pairs = 2 * pair_level;
	// std::cout << "Next_Pairs Calculate" << next_pairs << "\n";
	// next_pairs = 2 * pair_level;
	// std::cout << "Next_Pairs Rcursion Level" << next_pairs << "\n";
	for (Iterator it = start; it != very_last; std::advance(it, next_pairs), i++)
	{
		// std::cout << "In For Loop round: " << i << "\n";
		current_pair = next(it, pair_level - 1);
		// std::cout << "Post next call 1\n";
		next_pair = next(it, pair_level * 2 - 1);
		// std::cout << "Post next call 2\n";
		if (*current_pair > *next_pair)
		{
			// std::cout << "In if Condition\n";
			swap_pair(current_pair, pair_level);
		}
	}
	std::cout << "Post IterPAir Swap\n";
	// std::cout << "RdcursionsLEvel: " << pair_level << "\n";
	this->printContainer();
	sort(); //Rekursive Call (davor: sort(_container, pair_level * 2))
	/*TODO: here comes the Inertion Part:
		1. Initialize main & pend datastrucure (holding Iterators of jeweilige a und b Elemente)
		2. Insertion:
			2.1: Check wether pend elements higher than 3 --> yes (Insort(binary Insort) with Index of Jacobsthal Sequence), no (yes but without Jacobsthal)
			2.2: Init JacobsThal Container (en fonction du nombre absolue de la sequence)
				(argc - 1) / 2
				(22 - 1) / 2 = 11 --> wir brauchen bis einschließlich Jacobsthal nbr 11
			2.2: Insort Rest of Pend Elements (for example {b3, b2}, {b5, b4} --> always in the range of the current - prev Jacobsthal Sequence)
	*/
	std::deque<Iterator> main_chain;
	std::deque<Iterator> pend_chain;

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
	// exit(1);
}
//Sort -- END
