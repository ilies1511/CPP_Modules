#pragma once

// Includes --BEGIN
#include <algorithm>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>
#include <limits>
// Includes --END

//Class
class Span
{
	private:
		std::vector<int>	_numbers;
		unsigned int		_maxSize;
	//OCF
	public:
		Span(void);
		Span(unsigned int N);
		Span(const Span &og);
		Span &operator=(const Span &og);
		~Span(void);
	//Members
		void	addNumber(int Input);
		int		shortestSpan(void);
		int		longestSpan(void);
		//Template fnc
		template <typename Iterator>
		void	addRange(Iterator begin, Iterator end)
		{
			if (std::distance(begin, end) + _numbers.size() > _maxSize)
			{
				throw (std::runtime_error("Container size is too small to add the range!"));
			}
			_numbers.insert(_numbers.end(), begin, end);
		}
};
