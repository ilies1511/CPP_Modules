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
		Container					_jacobsthal_nbrs;
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
		void			processInput(void);
		// virtual void	sort(Container &_container, int recursion_level) = 0;
		virtual void	sort(void) = 0;
		int				cal_interPairSize(int recursion_level);
		void			displayOutput(void);
		void			printContainer(void);
		void			printContainerNormal(void);
		void			printContainerHoldingIterators(const std::deque<typename Container::iterator> &container);
		void			printContainerHoldingIterators_plus(const std::deque<typename Container::iterator> &container, int single_elements);
		void			validateSorting(const Container& container, const std::string& type);
		void			printContainerWithLimit(const Container &container, size_t limit = 300) const;
		//TODO: Add checkIfSorted check --> double checks if its sorted by traversing through container // std::is_sorted(_container.begin(), _container.end());
	//Methode
	private:
		void			initializeJacobsthalNumbers(void); //Gets calles in 'processInput()'
};

//Definitions of template FNCs
#include "PmergeMe.tpp"
