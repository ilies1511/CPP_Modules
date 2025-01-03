#pragma once

//Includes
#include "PmergeMe.hpp"

//Class
class DequePmergeMe : public PmergeMe<std::deque<int>>
{
	//OCF
	public:
		DequePmergeMe(int argc, char **argv);
		DequePmergeMe(const DequePmergeMe &og);
		DequePmergeMe &operator=(const DequePmergeMe &og);
		~DequePmergeMe(void);
	//Memebers
	public:
		void	sort() override;
};
