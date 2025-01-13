#include "DequePmergeMe.hpp"

//OCF -- BEGIN
DequePmergeMe::DequePmergeMe(int argc, char **argv) : PmergeMe(argc, argv)//, chains{0, 0, {}, {}, {}, {}, {}, {}, {}}
{
	printer::ocf_printer("DequePmergeMe", printer::OCF_TYPE::DC);
}

DequePmergeMe::DequePmergeMe(const DequePmergeMe &og) : PmergeMe(og)//, chains{0, 0, {}, {}, {}, {}, {}, {}, {}}
{
	printer::ocf_printer("DequePmergeMe", printer::OCF_TYPE::CC);
}

DequePmergeMe &DequePmergeMe::operator=(const DequePmergeMe &og)
{
	if (this != &og)
	{
		printer::ocf_printer("DequePmergeMe", printer::OCF_TYPE::CAC);
		PmergeMe::operator=(og);
		// this->chains = og.chains;
	}
	return (*this);
}

DequePmergeMe::~DequePmergeMe(void)
{
	printer::ocf_printer("DequePmergeMe", printer::OCF_TYPE::D);
}

template <typename T>
bool _comp(T lv, T rv)
{
	return (*lv < *rv);
}

//OCF -- END
void DequePmergeMe::sort(void)
{
	int			pair_units_nbr; //Amount of Pairs
	bool		is_odd;
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
		current_pair = next(it, pair_level - 1);
		next_pair = next(it, pair_level * 2 - 1);
		if (*current_pair > *next_pair)
		{
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

	printer::Header("In Insertion Part");
	this->printContainer();

	this->init_main_and_pendChain(main_chain, pend_chain, pair_level, pair_units_nbr);
	this->jacobsthal_based_insertion(main_chain, pend_chain);
	this->sequential_based_insertion(main_chain, pend_chain);
	if (is_odd)
	{
		auto odd_pair = next(very_last, pair_level - 1);
		auto idx = std::upper_bound(main_chain.begin(), main_chain.end(), odd_pair, _comp<Iterator>);
		main_chain.insert(idx, odd_pair);
	}
	printer::Header("PRE COPY");
	this->printContainer();

	this->reconstructContainer(main_chain, pair_level);

	printer::Header("POST reconstructContainer");
	this->printContainer();

	// exit(1);
}
//Sort -- END
