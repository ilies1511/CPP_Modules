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

//Own
#include "printer.hpp"


class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;
	//OCF
	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &og);
		PmergeMe &operator=(const PmergeMe &og);
		~PmergeMe(void);
	//Parser
	public:
		bool checkInput(int argc, char **argv);
};
