#include "PmergeMe.hpp"

//OCF -- BEGIN
template <typename Container>
PmergeMe<Container>::PmergeMe(int argc, char **argv)
	: _container(), _argc(argc), _argv(argv)
{
	printer::ocf_printer("PmergeMe", printer::OCF_TYPE::DC);
	try
	{
		processInput();
	}
	catch(const std::exception& e)
	{
		throw;
	}
}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe &og)
	: _container(og._container), _argc(og._argc), _argv(og._argv)
{
	printer::ocf_printer("PmergeMe", printer::OCF_TYPE::CC);
}

template <typename Container>
PmergeMe<Container>&PmergeMe<Container>::operator=(const PmergeMe &og)
{
	if (this != &og)
	{
		printer::ocf_printer("PmergeMe", printer::OCF_TYPE::CAC);
		this->_container = og._container;
		this->_argc = og._argc;
		this->_argv = og._argv;
	}
	return (*this);
}

template <typename Container>
PmergeMe<Container>::~PmergeMe(void)
{
	printer::ocf_printer("PmergeMe", printer::OCF_TYPE::D);
}

//OCF -- END

//Member - FNCs Definition

/*
	Handels Input like: ./PmergeMe 13 42 1 "124 14" 43
*/
template <typename Container>
void PmergeMe<Container>::processInput()
{
	int	number;
	std::string	token;

	std::cout << "In Process Input\n";
	for (int i = 1; i < _argc; i++)
	{
		std::istringstream	iss(_argv[i]);
		while (iss >> token)
		{
			if (!std::all_of(token.begin(), token.end(), ::isdigit))
				throw (std::invalid_argument("Invalid input (non-integer): " + token));
			number = std::stoi(token);
			if (number <= 0 || number > std::numeric_limits<int>::max())
				throw (std::invalid_argument("Invalid input (out of range): " + token));
			if (std::find(this->_container.begin(), this->_container.end(), number) != this->_container.end())
				throw std::invalid_argument("Duplicate input: " + token);
			// this->_container.push_back(number);
			this->_container.emplace_back(number);
		}
		if (iss.fail() && !iss.eof())
			throw (std::invalid_argument("Input parsing error for argument: " + std::string(_argv[i])));
	}
	std::cout << "POST insertion\n";
	for (size_t i = 0; i < _container.size(); i++)
	{
		std::cout << _container.at(i);
		if (i < _container.size() - 1)
		{
			std::cout << " ";
		}
	}
	std::cout << "\n";
}

template <typename Container>
void	PmergeMe<Container>::displayOutput()
{
	size_t	i;
	std::cout << "Test displayOutput() in .tpp file\n";
	std::chrono::high_resolution_clock::time_point	start;
	std::chrono::high_resolution_clock::time_point	end;
	std::chrono::duration<double, std::micro>		elapsed;

	std::cout << "Before: ";
	i = 0;
	for (typename Container::const_iterator it = _container.begin(); it != _container.end(); ++it, ++i)
	{
		std::cout << *it;
		if (_container.size() >= 300 && i == 5)
		{
			std::cout << " [...]\n";
			break;
		}
		if (i < _container.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
	start = std::chrono::high_resolution_clock::now();
	sort();
	end = std::chrono::high_resolution_clock::now();
	elapsed = end - start;
	std::cout << "Time to process a range of " << _container.size() \
		<< " elements with " << typeName<Container>() << ": " << elapsed.count() \
			<< " us" << std::endl;
	std::cout << "After: ";
	i = 0;
	for (typename Container::const_iterator it = _container.begin(); it != _container.end(); ++it, ++i)
	{
		std::cout << *it;
		if (_container.size() >= 300 && i == 5)
		{
			std::cout << " [...]\n";
			break;
		}
		if (i < _container.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

template <typename Container>
Container& PmergeMe<Container>::getContainer()
{
	return (_container);
}
template <typename Container>
void PmergeMe<Container>::printContainer(void)
{
	size_t i = 0;
	for (typename Container::const_iterator it = _container.begin(); it != _container.end(); ++it, i++)
	{
		std::cout << *it;
		if (i < _container.size() - 1)
			std::cout << " ";
	}
}


// Template Definitons

