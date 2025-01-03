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

//Own
#include "printer.hpp"

		// typedef std::pair<int, int>	Pair;
template <typename Container>
class PmergeMe
{
	protected:
		Container					_container;
		int							_argc;
		char						**_argv;
	//OCF
	public:
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe &og);
		PmergeMe &operator=(const PmergeMe &og);
		virtual ~PmergeMe(void);
	//Generic Member-FNCS
	public:
		bool			processInput();
		virtual void	sort() = 0;
		void			displayOutput() const;
};

//Definitions of template FNCs
#include "PmergeMe.tpp"
