#pragma once

//Includes
#include "PmergeMe.hpp"

//Class
class DequePmergeMe : public PmergeMe<std::deque<int>>
{
	public:
	//OCF
	public:
		DequePmergeMe(void);
		DequePmergeMe(int argc, char **argv);
		DequePmergeMe(const DequePmergeMe &og);
		DequePmergeMe &operator=(const DequePmergeMe &og);
		~DequePmergeMe(void);
	//Memebers
	private:
		// struct chain_struct
		// {
		// 	int						pair_level;
		// 	int						pair_units_nbr;
		// 	Iterator	start, last, very_last, current_pair, next_pair;
		// 	//Insortion Part -- BEGIN
		// 	std::deque<Iterator>	main_chain;
		// 	std::deque<Iterator>	pend_chain;
		// 	// int						prev_jacobsthal;
		// 	// int						inserted_numbers;
		// 	//Insortion Part -- END
		// };
		// chain_struct chains; // Instance of chain_struct for managing chains
	//Private Helper-FNCS
	private:
		void	init_main_and_pendChain(std::deque<Iterator> &main_chain, std::deque<Iterator> &pend_chain, int &pair_level, int &pair_units_nbr);
		void	jacobsthal_based_insertion(std::deque<Iterator> &main_chain, std::deque<Iterator> &pend_chain);
		void	sequential_based_insertion(std::deque<Iterator> &main_chain, std::deque<Iterator> &pend_chain);
		void	odd_insertion(std::deque<Iterator> &main_chain, Iterator &very_last, int &pair_level);
		void	entryPoint_Insertion(std::deque<Iterator> &main_chain, std::deque<Iterator> &pend_chain, int &pair_level, int &pair_units_nbr, bool &is_odd, Iterator &very_last);
		void	swap_pair(typename std::deque<int>::iterator it, int recursion_level);
		void	entryPoint_Merge(Iterator &start, Iterator &very_last, int &pair_level);
		void	reconstructContainer(std::deque<Iterator> &main_chain, int &pair_level);
		// void	odd_insertion(std::deque<Iterator> &main_chain, std::deque<Iterator> &pend_chain);
	public:
		// void sort(std::deque<int> &_container, int pair_level) override;
		void	sort(void) override;
};

// int		cal_interPairSize(int recursion_level);
