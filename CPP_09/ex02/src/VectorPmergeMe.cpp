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
	// int			next_pairs; //Steps to go until next pair
	Iterator	start, last, very_last;
//  current_pair, next_pair;
	int			pair_level;
	static int	recursion_level = 1;

	pair_level = cal_interPairSize(recursion_level++);
	is_odd = false;
	pair_units_nbr = static_cast<int>(_container.size()) / pair_level; //Break condition

	if (pair_units_nbr < 2) //BREAK-CONDTION: less than 2 pairs
		return ;

	// std::cout << "Pair Level: " << pair_level << "\n";

	is_odd = pair_units_nbr % 2 == 1;

	start = _container.begin();
	last = next(_container.begin(), pair_level * (pair_units_nbr));
	very_last = next(last, -(is_odd * pair_level));

	entryPoint_Merge(start, very_last, pair_level);
	// std::cout << "Post IterPAir Swap\n";
	// // std::cout << "RdcursionsLEvel: " << pair_level << "\n";
	// this->printContainer();
	sort(); //RECURSIV call until BREAK-CONDITION

	std::vector<Iterator> main_chain;
	std::vector<Iterator> pend_chain;

	// printer::Header("In Insertion Part");
	// this->printContainer();
	entryPoint_Insertion(main_chain, pend_chain, pair_level, pair_units_nbr, is_odd, very_last);
	// printer::Header("POST Insertion Part");
	// this->printContainer();

	// printer::Header("PRE Reconstruction");
	// this->printContainer();
	reconstructContainer(main_chain, pair_level);
	// printer::Header("POST Reconstruction");
	// this->printContainer();
	// exit(1);
}
