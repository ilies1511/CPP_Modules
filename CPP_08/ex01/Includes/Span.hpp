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
			if (static_cast<unsigned long>(std::distance(begin, end)) + _numbers.size() > _maxSize)
			{
				throw (std::runtime_error("Container size is too small to add the range!"));
			}
			_numbers.insert(_numbers.end(), begin, end);
		}
		//Getters
		unsigned int	getCapaciy(void) const;
		size_t			getSize(void) const;
	//Overload
	public:
		/*
			Overloeds '[]' operator in two ways:
				1. Returns reference from element --> enables its modification (write)
				2. Returns reference from element but CONST protect from modification --> enables its modification (only read)
		*/
		int& operator[](size_t index); //1
		const int& operator[](size_t index) const; //2
	//Exceptions:
	public:
		class OutOfBoundException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Index is out of bound !");
				}
		};
};
/*
	TODO:
		int& 	operator[](unsigned int index); Access --> both write & read
		getter fnc for size
*/

/*
	iterator insert(iterator pos, InputIterator first, InputIterator last):
		- pos: The position in the vector where new elements will be inserted.
		- first and last: Iterators specifying the range of elements to insert.
		In der Funktion fügt _numbers.insert(_numbers.end(), begin, end)
		alle Elemente, die im Bereich von begin bis end liegen, hinter dem
		letzten Element des Containers _numbers ein.
*/
