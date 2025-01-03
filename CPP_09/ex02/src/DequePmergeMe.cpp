#include "DequePmergeMe.hpp"

//OCF -- BEGIN
DequePmergeMe::DequePmergeMe(int argc, char **argv) : PmergeMe(argc, argv)
{
	printer::ocf_printer("DequePmergeMe", printer::OCF_TYPE::DC);
}

DequePmergeMe::DequePmergeMe(const DequePmergeMe &og) : PmergeMe(og)
{
	printer::ocf_printer("DequePmergeMe", printer::OCF_TYPE::CC);
}

DequePmergeMe &DequePmergeMe::operator=(const DequePmergeMe &og)
{
	if (this != &og)
	{
		printer::ocf_printer("DequePmergeMe", printer::OCF_TYPE::CAC);
		PmergeMe::operator=(og);
	}
	return (*this);
}

DequePmergeMe::~DequePmergeMe(void)
{
	printer::ocf_printer("DequePmergeMe", printer::OCF_TYPE::D);
}
//OCF -- END

void	DequePmergeMe::sort()
{
	std::cout << "In DequePmergeMe sort(): " << this->_argc << "\n";
}



