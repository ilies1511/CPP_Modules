#include "PmergeMe.hpp"

//OCF -- BEGIN
template <typename Container>
PmergeMe<Container>::PmergeMe(int argc, char **argv)
	: _container(), _argc(argc), _argv(argv), _jacobsthal_nbrs()
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
	: _container(og._container), _argc(og._argc), _argv(og._argv), _jacobsthal_nbrs(og._jacobsthal_nbrs)
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
		this->_jacobsthal_nbrs = og._jacobsthal_nbrs;
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
			if (number < 0 || number > std::numeric_limits<int>::max())
				throw (std::invalid_argument("Invalid input (out of range): " + token));
			// if (std::find(this->_container.begin(), this->_container.end(), number) != this->_container.end())
			// 	throw std::invalid_argument("Duplicate input: " + token);
			// this->_container.push_back(number);
			this->_container.emplace_back(number);
		}
		if (iss.fail() && !iss.eof())
			throw (std::invalid_argument("Input parsing error for argument: " + std::string(_argv[i])));
	}
	// std::cout << "POST insertion\n";
	for (size_t i = 0; i < _container.size(); i++)
	{
		std::cout << _container.at(i);
		if (i < _container.size() - 1)
		{
			std::cout << " ";
		}
	}
	std::cout << "\n";

	// Initialisiere die Jacobsthal-Zahlen
	initializeJacobsthalNumbers();
}

template <typename Container>
void	PmergeMe<Container>::displayOutput()
{
	size_t	i;
	// std::cout << "Test displayOutput() in .tpp file\n";
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
	// sort(this->_container, 1);
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
	size_t i = 1;
	for (typename Container::const_iterator it = _container.begin(); it != _container.end(); ++it, i++)
	{
		if (i % 2 != 0)
			std::cout << "(";
		std::cout << *it;
		if (i % 2 == 0)
			std::cout << ")";
		std::cout << " ";
	}
	std::cout << "\n";
}

template <typename Container>
void PmergeMe<Container>::printContainerNormal(void)
{
	for (typename Container::const_iterator it = _container.begin(); it != _container.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n";
}

// // template <typename Container>
// // void PmergeMe<Container>::printContainerHoldingIterators(Container &container)
// // {
// // 	size_t i = 1;
// // 	for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it, i++)
// // 	{
// // 		if (i % 2 != 0)
// // 			std::cout << "(";
// // 		std::cout << *(*it);
// // 		if (i % 2 == 0)
// // 			std::cout << ")";
// // 		std::cout << " ";
// // 	}
// // 	std::cout << "\n";
// // }

// template <typename Container>
// void PmergeMe<Container>::printContainerHoldingIterators(const Container &container)
// {
//     size_t i = 1;
//     for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it, ++i)
//     {
//         if (i % 2 != 0)
//             std::cout << "(";
//         std::cout << **it; // Doppelt dereferenzieren, da *it ein Iterator ist
//         if (i % 2 == 0)
//             std::cout << ")";
//         std::cout << " ";
//     }
//     std::cout << "\n";
// }

template <typename Container>
void validateSorting(const Container& container, const std::string& type)
{
	if (!std::is_sorted(container.begin(), container.end()))
	{
		std::cout << type << " Container not sorted: ";
		for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
		throw std::runtime_error(type + " Container not Sorted!");
	}
}

template <typename Container>
int PmergeMe<Container>::cal_interPairSize(int recursion_level)
{
	return (static_cast<int>(std::pow(2, recursion_level - 1)));
}

template <typename Container>
void PmergeMe<Container>::printContainerHoldingIterators_plus(const std::deque<typename Container::iterator> &container, int single_elements)
{
	size_t i = 1;
	int count = 0; // Counter for grouping elements
	for (typename std::deque<typename Container::iterator>::const_iterator it = container.begin(); it != container.end(); ++it, ++i)
	{
		if (count < single_elements)
		{
			std::cout << "(" << *(*it) << ") "; // Wrap each element in parentheses
			count++;
		}
		if (count == single_elements)
		{
			count = 0; // Reset count for the next group
		}
	}
	std::cout << "\n";
}

template <typename Container>
void PmergeMe<Container>::printContainerHoldingIterators(const std::deque<typename Container::iterator> &container)
{
	size_t i = 1;
	for (typename std::deque<typename Container::iterator>::const_iterator it = container.begin(); it != container.end(); ++it, ++i)
	{
		if (i % 2 != 0)
			std::cout << "(";
		std::cout << *(*it); // Doppelt dereferenzieren
		if (i % 2 == 0)
			std::cout << ")";
		std::cout << " ";
	}
	std::cout << "\n";
}

template <typename Container>
void PmergeMe<Container>::initializeJacobsthalNumbers()
{
	int	max_value; // Maximalwert basierend auf der Hälfte der Eingabesequenz
	int	j0;
	int	j1;
	int	j_next;

	max_value = static_cast<int>((_container.size() + 1)) / 2;
	j0 = 0;
	j1 = 1;

	_jacobsthal_nbrs.push_back(j0);
	_jacobsthal_nbrs.push_back(j1);
	// Berechne die weiteren Jacobsthal-Zahlen
	while (true)
	{
		j_next = j1 + 2 * j0;
		_jacobsthal_nbrs.push_back(j_next);
		j0 = j1;
		j1 = j_next;
		if (j_next > max_value)
			break;
	}
	// Debug Printer
	std::cout << "Jacobsthal Numbers: ";
	for (const auto &num : _jacobsthal_nbrs)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;
}
// Template Definitons
