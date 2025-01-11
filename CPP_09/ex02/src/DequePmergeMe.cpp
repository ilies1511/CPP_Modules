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


//Sort -- BEGIN
int	cal_interPairSize(int recursion_level)
{
	return (static_cast<int>(std::pow(2, recursion_level - 1)));
}

void	go2nextXPair(typename std::deque<int>::iterator it, int interPairSize)
{
	std::advance(it, interPairSize);
}

void	DequePmergeMe::swap_pair(typename std::deque<int>::iterator it, int pair_level)
{
	Iterator	start;
	Iterator	end;

	start = next(it, -pair_level + 1);
	end = next(start, pair_level);
	while (start != end)
	{
		std::iter_swap(start, next(start, pair_level));
		++start;
	}
}

typename std::deque<int>::iterator next(typename std::deque<int>::iterator it, int steps)
{
	std::advance(it, steps);
	return (it);
}

void DequePmergeMe::sort(void)
{
	int			pair_units_nbr; //Amount of Pairs
	bool		is_odd;
	// int			interPairSize;
	int			next_pairs; //Steps to go until next pair
	Iterator	start, last, very_last, current_pair, next_pair;
	int			pair_level;
	static int	recursion_level = 1; //TODO: add as private attribute in PmergeMe ?

	pair_level = cal_interPairSize(recursion_level++);
	is_odd = false;
	pair_units_nbr = static_cast<int>(_container.size()) / pair_level; //Break condition

	if (pair_units_nbr < 2)
		return ;

	std::cout << "Pair Level: " << pair_level << "\n";

	is_odd = pair_units_nbr % 2 == 1;

	start = _container.begin();
	last = next(_container.begin(), pair_level * (pair_units_nbr));
	very_last = next(last, -(is_odd * pair_level));

	size_t i = 0;
	next_pairs = 2 * pair_level;
	// std::cout << "Next_Pairs Calculate" << next_pairs << "\n";
	// next_pairs = 2 * pair_level;
	// std::cout << "Next_Pairs Rcursion Level" << next_pairs << "\n";
	for (Iterator it = start; it != very_last; std::advance(it, next_pairs), i++)
	{
		// std::cout << "In For Loop round: " << i << "\n";
		current_pair = next(it, pair_level - 1);
		// std::cout << "Post next call 1\n";
		next_pair = next(it, pair_level * 2 - 1);
		// std::cout << "Post next call 2\n";
		if (*current_pair > *next_pair)
		{
			// std::cout << "In if Condition\n";
			swap_pair(current_pair, pair_level);
		}
	}
	std::cout << "Post IterPAir Swap\n";
	// std::cout << "RdcursionsLEvel: " << pair_level << "\n";
	this->printContainer();
	sort(); //Rekursive Call (davor: sort(_container, pair_level * 2))
}
//Sort -- END
