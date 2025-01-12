#pragma once

//Includes
	//Project-Specific Containers -- BEGIN
#include <deque>
#include <vector>
	//Project-Specific Containers -- END
#include <iomanip> //Precision
#include <stdbool.h> //Bool
	//Parsing -- BEGIN
#include <sstream>
#include <fstream>
#include <limits>
#include <regex>
	//Parsing -- END
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <string>
	//Exception
#include <stdexcept>
#include <chrono> //Time-Measurement
#include "typeName.hpp"
#include "cmath"


//Own
#include "printer.hpp"

// typedef std::pair<int, int>	Pair;make
template <typename Container>
class PmergeMe
{
	protected:
		Container					_container;
		int							_argc;
		char						**_argv;
		//TODO: Add generic (const) iterator (should work for at least vector & deque)
	//typedefs for Iteraotrs
	protected:
		typedef typename Container::iterator Iterator;
		typedef typename Container::const_iterator ConstIterator;
	//OCF
	public:
		PmergeMe(int argc, char **argv); //TODO: Add default constructor and init Container with random values
		PmergeMe(const PmergeMe &og);
		PmergeMe &operator=(const PmergeMe &og);
		virtual ~PmergeMe(void);
	public:
		Container& getContainer();
	//Generic Member-FNCS
	public:
		void			processInput();
		// virtual void	sort(Container &_container, int recursion_level) = 0;
		virtual void	sort(void) = 0;
		void			displayOutput();
		void 			printContainer(void);
		void			printContainerHoldingIterators(const std::deque<typename Container::iterator> &container);
		//TODO: Add checkIfSorted check --> double checks if its sorted by traversing through container // std::is_sorted(_container.begin(), _container.end());
};

//Definitions of template FNCs
#include "PmergeMe.tpp"
