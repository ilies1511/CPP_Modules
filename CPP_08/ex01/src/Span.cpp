#include "Span.hpp"
#include "printer.hpp"

//OCF--BEGIN
Span::Span(void) : _maxSize(0)
{
	printer::ocf_printer("Span", printer::OCF_TYPE::DC);
}

Span::Span(unsigned int N) : _maxSize(N)
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
	auto sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	auto min_span = std::numeric_limits<int>::max(); // Highest dataTyp for ints
	for (auto i = 1; i < sorted.size(); i++)
	{
		// if (sorted[i] - sorted[i - 1] < min_span)
		// 	min_span = sorted[i] - sorted[i - 1];
		auto span = sorted[i] - sorted[i - 1];
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
	auto minmax = std::minmax_element(_numbers.begin(), _numbers.end());
	return (*minmax.second - *minmax.first);
}


