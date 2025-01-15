#include "VectorPmergeMe.hpp"

//Sort -- BEGIN
//Helpers -- BEGIN

void	VectorPmergeMe::swap_pair(typename std::vector<int>::iterator it, int pair_level)
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

typename std::vector<int>::iterator next(typename std::vector<int>::iterator it, int steps)
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

// void	VectorPmergeMe::reconstructContainer(std::vector<Iterator> &main_chain, int &pair_level)
// {
// 	// std::vector<int> copy;
// 	// copy.reserve(_container.size());
// 	// for (auto it = main_chain.begin(); it != main_chain.end(); it++)
// 	// {
// 	// 	for (int i = 0; i < pair_level; i++)
// 	// 	{
// 	// 		Iterator pair_start = *it;
// 	// 		std::advance(pair_start, -pair_level + i + 1);
// 	// 		copy.insert(copy.end(), *pair_start);
// 	// 	}
// 	// }
// 	// Iterator container_it = _container.begin();
// 	// std::vector<int>::iterator copy_it = copy.begin();
// 	// while (copy_it != copy.end())
// 	// {
// 	// 	*container_it = *copy_it;
// 	// 	container_it++;
// 	// 	copy_it++;
// 	// }
// }

//ALGO-specific -- BEGIN
void	VectorPmergeMe::reconstructContainer(std::vector<Iterator> &main_chain, int &pair_level)
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



void	VectorPmergeMe::odd_insertion(std::vector<Iterator> &main_chain, Iterator &very_last, int &pair_level)
{
	auto odd_pair = next(very_last, pair_level - 1);
	auto idx = std::upper_bound(main_chain.begin(), main_chain.end(), odd_pair, _comp<Iterator>);
	main_chain.insert(idx, odd_pair);
}

void	VectorPmergeMe::sequential_based_insertion(std::vector<Iterator> &main_chain, std::vector<Iterator> &pend_chain)
{
	for (size_t i = 0; i < pend_chain.size(); i++)
	{
		auto curr_pend = next(pend_chain.begin(), static_cast<typename std::vector<Iterator>::difference_type>(i));
		auto curr_bound = next(main_chain.begin(), static_cast<typename std::vector<Iterator>::difference_type>(main_chain.size() - pend_chain.size() + i));
		auto idx = std::upper_bound(main_chain.begin(), curr_bound, *curr_pend, _comp<Iterator>);
		main_chain.insert(idx, *curr_pend);
	}
}


void	VectorPmergeMe::jacobsthal_based_insertion(std::vector<Iterator> &main_chain, std::vector<Iterator> &pend_chain)
{
	int	prev_jacobsthal;
	int	inserted_numbers;
	int	jacobsthal_diff;
	int offset;
	int curr_jacobsthal;

	prev_jacobsthal = this->_jacobsthal_nbrs.at(2); // 0 1 1 3 5
	inserted_numbers = 0;
	for (size_t k = 3;; k++)
	{
		curr_jacobsthal = this->_jacobsthal_nbrs.at(k);
		jacobsthal_diff = curr_jacobsthal - prev_jacobsthal;
		offset = 0;
		if (jacobsthal_diff > static_cast<int>(pend_chain.size()))
			break;
		auto pend_it = next(pend_chain.begin(), jacobsthal_diff - 1);
		auto bound_it =	next(main_chain.begin(), curr_jacobsthal + inserted_numbers);
		for (int i = 0; i < jacobsthal_diff; i++)
		{
			auto idx = std::upper_bound(main_chain.begin(), bound_it, *pend_it, _comp<Iterator>);
			auto inserted = main_chain.insert(idx, *pend_it);
			pend_it = pend_chain.erase(pend_it);
			std::advance(pend_it, -1);
			offset += (inserted - main_chain.begin()) == curr_jacobsthal + inserted_numbers;
			bound_it = next(main_chain.begin(), curr_jacobsthal + inserted_numbers - offset);
		}
		prev_jacobsthal = curr_jacobsthal;
		inserted_numbers += jacobsthal_diff;
		offset = 0;
	}
}

void	VectorPmergeMe::init_main_and_pendChain(std::vector<Iterator> &main_chain, \
	std::vector<Iterator> &pend_chain, int &pair_level, int &pair_units_nbr)
{
	int pair_index = 2; // Startindex für die Paare (entspricht 2. und 4. Element)
	do
	{
		if (pair_index == 2)
		{
			main_chain.insert(main_chain.end(), next(_container.begin(), pair_level - 1)); // b1
			main_chain.insert(main_chain.end(), next(_container.begin(), (pair_level * 2) - 1)); // a1
		}
		else
		{
			pend_chain.insert(pend_chain.end(), next(_container.begin(), pair_level * (pair_index - 1) - 1));
			main_chain.insert(main_chain.end(), next(_container.begin(), pair_level * pair_index - 1));
		}
		pair_index += 2;
	}
	while (pair_index <= pair_units_nbr);
}

void	VectorPmergeMe::entryPoint_Insertion(std::vector<Iterator> &main_chain, \
	std::vector<Iterator> &pend_chain, int &pair_level, int &pair_units_nbr, bool &is_odd, Iterator &very_last)
{
	init_main_and_pendChain(main_chain, pend_chain, pair_level, pair_units_nbr);
	jacobsthal_based_insertion(main_chain, pend_chain);
	sequential_based_insertion(main_chain, pend_chain);
	if (is_odd)
		odd_insertion(main_chain, very_last, pair_level);
}

void	VectorPmergeMe::entryPoint_Merge(Iterator &start, Iterator &very_last, int &pair_level)
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
