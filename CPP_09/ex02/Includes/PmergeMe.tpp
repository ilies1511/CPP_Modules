#include "PmergeMe.hpp"

//OCF -- BEGIN
template <typename Container>
PmergeMe<Container>::PmergeMe(int argc, char **argv)
	: _container(), _argc(argc), _argv(argv)
{
	printer::ocf_printer("PmergeMe", printer::OCF_TYPE::DC);
}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe &og)
	: _container(og._container), _argc(og._argc), _argv(og._argv)
{
	printer::ocf_printer("PmergeMe", printer::OCF_TYPE::CC);
}

template <typename Container>
PmergeMe<Container>&PmergeMe<Container>::operator=(const PmergeMe &og)
{
	if (this != &og)
	{
		printer::ocf_printer("PmergeMe", printer::OCF_TYPE::CAC);
		this->_container = og._container;
		this->_argc = og._argc;
		this->_argv = og._argv;
	}
	return (*this);
}

template <typename Container>
PmergeMe<Container>::~PmergeMe(void)
{
	printer::ocf_printer("PmergeMe", printer::OCF_TYPE::D);
}

//OCF -- END

//Member - FNCs Definition
template <typename Container>
bool PmergeMe<Container>::processInput()
{
	std::cout << "Test processInput() in .tpp file\n";
}

template <typename Container>
void	PmergeMe<Container>::displayOutput()const
{
	std::cout << "Test displayOutput() in .tpp file\n";
}

// Template Definitons
