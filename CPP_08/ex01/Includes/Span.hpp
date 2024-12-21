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
		void	addNumber(size_t Input);
		size_t	shortestSpan(void);
		size_t	longestSpan(void);
		//Template fnc
		template <typename Iterator>
		void	addRange(Iterator begin, Iterator end)
		{
			if (std::distance(begin, last) + _numbers.size() > _maxSize)
			{
				throw (std::runtime_error("Containe Size is to small !"));
			}
			_numbers.insert(_numbers.end(), begin, end);
		}
};
