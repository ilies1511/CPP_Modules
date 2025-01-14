#include "VectorPmergeMe.hpp"

//OCF -- BEGIN
VectorPmergeMe::VectorPmergeMe(int argc, char **argv) : PmergeMe(argc, argv)
{
	printer::ocf_printer("VectorPmergeMe", printer::OCF_TYPE::DC);
}

VectorPmergeMe::VectorPmergeMe(const VectorPmergeMe &og) :  PmergeMe(og)
{
	printer::ocf_printer("VectorPmergeMe", printer::OCF_TYPE::CC);
}

VectorPmergeMe &VectorPmergeMe::operator=(const VectorPmergeMe &og)
{
	if (this != &og)
	{
		printer::ocf_printer("VectorPmergeMe", printer::OCF_TYPE::CAC);
		PmergeMe::operator=(og);
	}
	return (*this);
}

VectorPmergeMe::~VectorPmergeMe(void)
{
	printer::ocf_printer("VectorPmergeMe", printer::OCF_TYPE::D);
}
//OCF -- END

// void VectorPmergeMe::sort(std::vector<int> &_container, int recursion_level)
void VectorPmergeMe::sort()
{
	int			pair_units_nbr; //Amount of Pairs
	bool		is_odd;
	Iterator	start, last, very_last;
	int			pair_level;
	static int	recursion_level = 1;

	pair_level = cal_interPairSize(recursion_level++);
	is_odd = false;
	pair_units_nbr = static_cast<int>(_container.size()) / pair_level; //Break condition

	if (pair_units_nbr < 2) //BREAK-CONDTION: less than 2 pairs
		return ;

	is_odd = pair_units_nbr % 2 == 1;
	start = _container.begin();
	last = next(_container.begin(), pair_level * (pair_units_nbr));
	very_last = next(last, -(is_odd * pair_level));
	entryPoint_Merge(start, very_last, pair_level);
	sort(); //RECURSIV call until BREAK-CONDITION

	std::vector<Iterator> main_chain;
	std::vector<Iterator> pend_chain;

	entryPoint_Insertion(main_chain, pend_chain, pair_level, pair_units_nbr, is_odd, very_last);
	reconstructContainer(main_chain, pair_level);
}
