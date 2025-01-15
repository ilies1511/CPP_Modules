/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DequePmergeMe.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:08:30 by iziane            #+#    #+#             */
/*   Updated: 2025/01/15 23:08:31 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DequePmergeMe.hpp"

//OCF -- BEGIN
DequePmergeMe::DequePmergeMe(void) : PmergeMe()
{
	printer::ocf_printer("VectorPmergeMe", printer::OCF_TYPE::DC);
}

DequePmergeMe::DequePmergeMe(int argc, char **argv) : PmergeMe(argc, argv)//, chains{0, 0, {}, {}, {}, {}, {}, {}, {}}
{
	printer::ocf_printer("DequePmergeMe", printer::OCF_TYPE::DC);
}

DequePmergeMe::DequePmergeMe(const DequePmergeMe &og) : PmergeMe(og)//, chains{0, 0, {}, {}, {}, {}, {}, {}, {}}
{
	printer::ocf_printer("DequePmergeMe", printer::OCF_TYPE::CC);
}

DequePmergeMe &DequePmergeMe::operator=(const DequePmergeMe &og)
{
	if (this != &og)
	{
		printer::ocf_printer("DequePmergeMe", printer::OCF_TYPE::CAC);
		PmergeMe::operator=(og);
		// this->chains = og.chains;
	}
	return (*this);
}

DequePmergeMe::~DequePmergeMe(void)
{
	printer::ocf_printer("DequePmergeMe", printer::OCF_TYPE::D);
}

template <typename T>
bool _comp(T lv, T rv)
{
	return (*lv < *rv);
}

//OCF -- END
void DequePmergeMe::sort(void)
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

	std::deque<Iterator> main_chain;
	std::deque<Iterator> pend_chain;

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
//Sort -- END
