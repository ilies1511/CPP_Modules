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
#include <deque>
#include <stack>
#include "printer.hpp"
// Includes --END
//Class--BEGIN
// template <class Type, class Container = deque<Type> > class stack;
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	private:
	//OCF
	public:
		MutantStack(void);
		MutantStack(const MutantStack &og);
		MutantStack &operator=(const MutantStack &og);
		~MutantStack(void);
	//Members-Iterators
		/*

		*/
		typedef typename std::stack<T, Container>::container_type::iterator iterator;// Less robust syntax: typedef typename Container::iterator	iterator;
		typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;
		//Iterator Functions
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
};
//Class--END


#include "MutantStack.tpp" //LAST LINE: END
