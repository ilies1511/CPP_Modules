#pragma once

//Includes
#include "PmergeMe.hpp"

//Class
class VectorPmergeMe : public PmergeMe<std::vector<int>>
{
	//OCF
	public:
		VectorPmergeMe(int argc, char **argv);
		VectorPmergeMe(const VectorPmergeMe &og);
		VectorPmergeMe &operator=(const VectorPmergeMe &og);
		~VectorPmergeMe(void);
	//Memebers
	//Private Helper-FNCS
	private:
		void	init_main_and_pendChain(std::vector<Iterator> &main_chain, std::vector<Iterator> &pend_chain, int &pair_level, int &pair_units_nbr);
		void	jacobsthal_based_insertion(std::vector<Iterator> &main_chain, std::vector<Iterator> &pend_chain);
		void	sequential_based_insertion(std::vector<Iterator> &main_chain, std::vector<Iterator> &pend_chain);
		void	odd_insertion(std::vector<Iterator> &main_chain, Iterator &very_last, int &pair_level);
		void	entryPoint_Insertion(std::vector<Iterator> &main_chain, std::vector<Iterator> &pend_chain, int &pair_level, int &pair_units_nbr, bool &is_odd, Iterator &very_last);
		void	swap_pair(typename std::vector<int>::iterator it, int recursion_level);
		void	entryPoint_Merge(Iterator &start, Iterator &very_last, int &pair_level);
		void	reconstructContainer(std::vector<Iterator> &main_chain, int &pair_level);
	public:
		void	sort(void) override;
};
