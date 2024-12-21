#include "Span.hpp"
#include "printer.hpp"

//OCF--BEGIN
Span::Span(void) : _numbers(), _maxSize(0)
{
	printer::ocf_printer("Span", printer::OCF_TYPE::DC);
}

Span::Span(unsigned int N) : _numbers(), _maxSize(N)
{
	printer::ocf_printer("Span", printer::OCF_TYPE::DNC);
}

Span::Span(const Span &og) : _numbers(og._numbers), _maxSize(og._maxSize)
{
	printer::ocf_printer("Span", printer::OCF_TYPE::CC);
}

Span &Span::operator=(const Span &og)
{
	if (this != &og)
	{
		this->_numbers = og._numbers;
		this->_maxSize = og._maxSize;
		printer::ocf_printer("Span", printer::OCF_TYPE::CAC);
	}
	return (*this);
}

Span::~Span(void)
{
	printer::ocf_printer("Span", printer::OCF_TYPE::D);
}

void	Span::addNumber(int Input)
{
	if (_numbers.size() >= _maxSize)
	{
		throw(std::runtime_error("Failed to add Element. Container is Full !"));
	}
	_numbers.push_back(Input);
}

int	Span::shortestSpan(void)
{
	if (_numbers.size() < 2)
	{
		throw std::logic_error("Not enough numbers to calculate span !");
	}
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	int min_span = std::numeric_limits<int>::max(); // Highest dataTyp for ints
	for (size_t i = 1; i < sorted.size(); i++)
	{
		// if (sorted[i] - sorted[i - 1] < min_span)
		// 	min_span = sorted[i] - sorted[i - 1];
		int span = sorted[i] - sorted[i - 1];
		min_span = std::min(min_span, span); // Keep the smallest span
	}
	return (min_span);
}

int	Span::longestSpan(void)
{
	if (_numbers.size() < 2)
	{
		throw std::logic_error("Not enough numbers to calculate span !");
	}
	std::pair<std::vector<int>::iterator, std::vector<int>::iterator> minmax = \
		std::minmax_element(_numbers.begin(), _numbers.end());
	return (*minmax.second - *minmax.first);
}

//Getters--BEGIN
unsigned int	Span::getCapaciy(void) const
{
	return (this->_maxSize);
}

size_t	Span::getSize(void) const
{
	return (this->_numbers.size());
}
//Getters--END

//Overloeds '[]'-- BEGIN
int& Span::operator[](size_t index)
{
	if (index >= this->getSize())
		throw (OutOfBoundException());
	return _numbers[index];
}

const int& Span::operator[](size_t index) const
{
	if (index >= this->getSize())
		throw (OutOfBoundException());
	return _numbers[index];
}
//Overloeds '[]'-- END


/*
	std::pair<std::vector<int>::iterator, std::vector<int>::iterator> minmax = \
		std::minmax_element(_numbers.begin(), _numbers.end());

	This function takes a range (defined by two iterators) and returns a
	std::pair of iterators:
		first: An iterator pointing to the smallest element in the range
		second: An iterator pointing to the largest element in the range.

	_numbers is a std::vector<int>, so its iterator type is std::vector<int>::iterator

	Result Type:

	Since std::minmax_element returns a pair of iterators for the range of
	_numbers, the type of minmax is:
		std::pair<std::vector<int>::iterator, std::vector<int>::iterator>
*/
