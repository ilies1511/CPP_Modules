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

void	VectorPmergeMe::sort()
{
	std::cout << "In VectorPmergeMe sort()\n";
}
