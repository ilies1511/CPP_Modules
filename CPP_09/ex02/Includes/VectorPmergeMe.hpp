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
	public:
		void sort(std::vector<int> &_container, int recursion_level) override;
};
