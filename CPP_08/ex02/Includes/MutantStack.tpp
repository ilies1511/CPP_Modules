#pragma once

#include "MutantStack.hpp" //FIRST LINE

//OCF--BEGIN
template <typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>()
{
	printer::ocf_printer("MutantStack", printer::OCF_TYPE::DC);
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack &og)
	: std::stack<T, Container>(og)
{
	printer::ocf_printer("MutantStack", printer::OCF_TYPE::CC);
}

template <typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& og)
{
	if (this != og)
	{
		printer::ocf_printer("MutantStack", printer::OCF_TYPE::CAC);
		std::stack<T, Container>::operator=(og);
	}
	return (*this);
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{
	printer::ocf_printer("MutantStack", printer::OCF_TYPE::D);
}
//OCF--END


//Iterators--BEGIN
template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
	return (this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
	return (this->c.end());
}

// Begin Iterator (Const)
template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin() const
{
	return (this->c.begin());
}

// End Iterator (Const)
template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end() const
{
	return (this->c.end());
}
//Iterators--END
