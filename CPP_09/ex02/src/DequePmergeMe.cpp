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
	return (static_cast<int>(std::pow(2, recursion_level)));
}

void	go2nextXPair(typename std::deque<int>::iterator it, int interPairSize)
{
	std::advance(it, interPairSize);
}

void	swap_pair(typename std::deque<int>::iterator it, int recursion_level)
{
	typedef typename std::deque<int>::iterator Iterator;

	// std::cout << "Range: " << recursion_level << "\n";
	// std::cout << "In swap_Pair for it: " << *it << "\n";

	Iterator start = next(it, -recursion_level + 1);
	Iterator end = next(it, recursion_level);

	// std::cout << "In swap_Pair for start: " << *start << "\n";
	// std::cout << "In swap_Pair for end: " << *end << "\n";

	while (start != end)
	{
		std::iter_swap(start, next(start, recursion_level));
		start++;
	}
}

typename std::deque<int>::iterator next(typename std::deque<int>::iterator it, int steps)
{
	std::advance(it, steps);
	return (it);
}

void DequePmergeMe::sort(std::deque<int> &_container, int recursion_level)
{
	int			pair_units_nbr;
	bool		is_odd;
	int			interPairSize;
	int			next_pairs;
	Iterator	start;
	Iterator	last;
	Iterator	very_last;
	Iterator	current_pair;
	Iterator	next_pair;

	interPairSize = cal_interPairSize(recursion_level);
	is_odd = false;
	this->printContainer();
	std::cout << "Recursion_level: " << recursion_level << "\n";
	pair_units_nbr = static_cast<int>(_container.size()) / recursion_level; //Break condition

	if (pair_units_nbr < 2)
		return ;

	is_odd = pair_units_nbr % 2 == 1;

	start = _container.begin();
	last = next(_container.begin(), recursion_level * (pair_units_nbr));
	very_last = next(last, -(is_odd * recursion_level));

	size_t i = 0;
	next_pairs = cal_interPairSize(recursion_level);
	// std::cout << "Next_Pairs Calculate" << next_pairs << "\n";
	// next_pairs = 2 * recursion_level;
	// std::cout << "Next_Pairs Rcursion Level" << next_pairs << "\n";
	for (Iterator it = start; it != very_last; std::advance(it, next_pairs), i++)
	{
		// std::cout << "In For Loop round: " << i << "\n";
		current_pair = next(it, recursion_level - 1);
		// std::cout << "Post next call 1\n";
		next_pair = next(it, recursion_level * 2 - 1);
		// std::cout << "Post next call 2\n";
		if (*next_pair < *current_pair)
		{
			// std::cout << "In if Condition\n";
			swap_pair(current_pair, recursion_level);
		}
	}
	std::cout << "Post IterPAir Swap\n";
	this->printContainer();
}
//Sort -- END
