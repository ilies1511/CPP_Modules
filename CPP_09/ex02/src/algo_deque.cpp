#include "DequePmergeMe.hpp"

//Sort -- BEGIN
//Helpers -- BEGIN
// int	cal_interPairSize(int recursion_level)
// {
// 	return (static_cast<int>(std::pow(2, recursion_level - 1)));
// }

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
//Helpers -- END

//ALGO-specific -- BEGIN
// void	DequePmergeMe::reconstructContainer(std::deque<Iterator> &main_chain, int &pair_level)
// {
// 	std::vector<int> copy;
// 	// printer::Header("In reconstructContainer");
// 	copy.reserve(_container.size());
// 	for (auto it = main_chain.begin(); it != main_chain.end(); it++)
// 	{
// 		for (int i = 0; i < pair_level; i++)
// 		{
// 			Iterator pair_start = *it;
// 			std::advance(pair_start, -pair_level + i + 1);
// 			copy.insert(copy.end(), *pair_start);
// 			// printer::Header("Inner Loop");
// 			// for (auto it = copy.begin(); it != copy.end(); ++it)
// 			// 	std::cout << *it << " ";
// 		}
// 		// printer::Header("Outer Loop");
// 		// for (auto it = copy.begin(); it != copy.end(); ++it)
// 		// 	std::cout << *it << " ";
// 	}
// 	// printer::Header("After Nested Loop");
// 	// for (auto it = copy.begin(); it != copy.end(); ++it)
// 	// 	std::cout << *it << " ";

// 	// Replace values in the original container
// 	Iterator container_it = _container.begin();
// 	std::vector<int>::iterator copy_it = copy.begin();
// 	while (copy_it != copy.end())
// 	{
// 		*container_it = *copy_it;
// 		container_it++;
// 		copy_it++;
// 	}
// 	// printer::Header("POST COPY");
// 	// this->printContainer();
// }

void	DequePmergeMe::reconstructContainer(std::deque<Iterator> &main_chain, int &pair_level)
{
	std::vector<int> copy;
	copy.reserve(_container.size());
	for (const auto &it : main_chain)
	{
		for (int i = 0; i < pair_level; ++i)
		{
			Iterator pair_start = it;
			std::advance(pair_start, -pair_level + i + 1);
			copy.push_back(*pair_start);
		}
	}
	std::copy(copy.begin(), copy.end(), _container.begin());
}

void	DequePmergeMe::odd_insertion(std::deque<Iterator> &main_chain, Iterator &very_last, int &pair_level)
{
	auto odd_pair = next(very_last, pair_level - 1);
	auto idx = std::upper_bound(main_chain.begin(), main_chain.end(), odd_pair, _comp<Iterator>);
	main_chain.insert(idx, odd_pair);
}

void	DequePmergeMe::sequential_based_insertion(std::deque<Iterator> &main_chain, std::deque<Iterator> &pend_chain)
{
	// printer::Header("In sequential_based_insertion");
	// printContainerNormal();
	for (size_t i = 0; i < pend_chain.size(); i++)
	{
		auto curr_pend = next(pend_chain.begin(), static_cast<typename std::deque<Iterator>::difference_type>(i));
		auto curr_bound = next(main_chain.begin(), static_cast<typename std::deque<Iterator>::difference_type>(main_chain.size() - pend_chain.size() + i));
		auto idx = std::upper_bound(main_chain.begin(), curr_bound, *curr_pend, _comp<Iterator>);
		main_chain.insert(idx, *curr_pend);
	}
}


void	DequePmergeMe::jacobsthal_based_insertion(std::deque<Iterator> &main_chain, std::deque<Iterator> &pend_chain)
{
	int	prev_jacobsthal;
	int	inserted_numbers;
	int	jacobsthal_diff;
	int offset;
	int nbr_of_times;

	// printer::Header("In jacobsthal_based_insertion");

	// printer::Header("Main Chain");
	// printContainerHoldingIterators(main_chain);
	// printer::Header("Pend Chain");
	// printContainerHoldingIterators(pend_chain);
	// printer::Header("Print Container");
	// printContainer();
	prev_jacobsthal = this->_jacobsthal_nbrs.at(2); // 0 1 1 3 5
	inserted_numbers = 0;
	for (size_t k = 3;; k++)
	{
		// std::cout << "PRE JT at Call\n";
		int curr_jacobsthal = this->_jacobsthal_nbrs.at(k);
		// std::cout << "POST JT at Call\n";
		// std::cout << "Current Jacobsthal_number: " << curr_jacobsthal << "\n";
		// std::cout << "Prev Jacobsthal_number: " << prev_jacobsthal << "\n";
		jacobsthal_diff = curr_jacobsthal - prev_jacobsthal;
		offset = 0;
		if (jacobsthal_diff > static_cast<int>(pend_chain.size()))
			break;
		nbr_of_times = jacobsthal_diff;
		auto pend_it = next(pend_chain.begin(), jacobsthal_diff - 1);
		auto bound_it =	next(main_chain.begin(), curr_jacobsthal + inserted_numbers);
		while (nbr_of_times)
		{
			auto idx = std::upper_bound(main_chain.begin(), bound_it, *pend_it, _comp<Iterator>);
			auto inserted = main_chain.insert(idx, *pend_it);
			nbr_of_times--;
			pend_it = pend_chain.erase(pend_it);
			std::advance(pend_it, -1);

			offset += (inserted - main_chain.begin()) == curr_jacobsthal + inserted_numbers;
			bound_it = next(main_chain.begin(), curr_jacobsthal + inserted_numbers - offset);
			// printer::Header("In Number of TIMES LOOP");
			// printer::Header("Main Chain");
			// printContainerHoldingIterators(main_chain);
			// printer::Header("Pend Chain");
			// printContainerHoldingIterators(pend_chain);
			// printer::Header("Print Container");
			// printContainer();
		}
		prev_jacobsthal = curr_jacobsthal;
		inserted_numbers += jacobsthal_diff;
		offset = 0;
	}
	// printer::Header("POST jacobsthal_based_insertion");
	// printer::Header("Main Chain");
	// printContainerHoldingIterators(main_chain);
	// printer::Header("Pend Chain");
	// printContainerHoldingIterators(pend_chain);
	// printer::Header("Print Container");
	// printContainer();
}

void	DequePmergeMe::init_main_and_pendChain(std::deque<Iterator> &main_chain, \
	std::deque<Iterator> &pend_chain, int &pair_level, int &pair_units_nbr)
{
	// printer::Header("In Insertion Part");
	// this->printContainer();

	// printer::Header("Init MAIN -& PEND-CHAIN");
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

	// printer::Header("Main-Chain");
	// this->printContainerHoldingIterators_plus(main_chain, static_cast<int>(main_chain.size()));
	// std::cout << coloring("Single Elements in Pend: " + std::to_string(pend_chain.size()) + "\n", PURPLE);
	// printer::Header("Pend-Chain");
	// this->printContainerHoldingIterators_plus(pend_chain, static_cast<int>(pend_chain.size()));
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
