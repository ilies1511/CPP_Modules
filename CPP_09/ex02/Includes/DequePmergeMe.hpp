#pragma once

//Includes
#include "PmergeMe.hpp"

//Class
class DequePmergeMe : public PmergeMe<std::deque<int>>
{
	//Iterators:
		typedef typename std::deque<int>::iterator Iterator;
		typedef typename std::deque<int>::const_iterator ConstIterator;
		// typedef typename std::deque<int>::const_iterator const_it;
		// typedef typename std::deque<int>::reverse_iterator rev_it;
		// typedef typename std::deque<int>::const_reverse_iterator const_rev_it;
	public:
	//OCF
	public:
		DequePmergeMe(int argc, char **argv);
		DequePmergeMe(const DequePmergeMe &og);
		DequePmergeMe &operator=(const DequePmergeMe &og);
		~DequePmergeMe(void);
	//Memebers
	private:
		void	swap_pair(typename std::deque<int>::iterator it, int recursion_level);
	public:
		// void sort(std::deque<int> &_container, int pair_level) override;
		void sort(void) override;
};
