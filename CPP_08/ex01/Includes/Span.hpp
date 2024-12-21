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
		unsigned int		_maxSize; //the maximum capacity
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
			//Check for capacity
			if (std::distance(begin, end) + _numbers.size() > _maxSize)
			{
				throw (std::runtime_error("Container size is too small to add the range!"));
			}
			_numbers.insert(_numbers.end(), begin, end);
		}
};


/*
	iterator insert(iterator pos, InputIterator first, InputIterator last):
		- pos: The position in the vector where new elements will be inserted.
		- first and last: Iterators specifying the range of elements to insert.
		In der Funktion fügt _numbers.insert(_numbers.end(), begin, end)
		alle Elemente, die im Bereich von begin bis end liegen, hinter dem
		letzten Element des Containers _numbers ein.
*/
