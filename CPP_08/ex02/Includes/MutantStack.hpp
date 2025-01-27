/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:20:31 by iziane            #+#    #+#             */
/*   Updated: 2024/12/22 18:20:32 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	// // Universal Push Method
	// public:
	// 	template <typename U = Container>
	// 	typename std::enable_if<std::is_same<U, std::list<T>>::value>::type push(const T& value)
	// 	{
	// 		this->c.push_back(value);
	// 	}
	// 	template <typename U = Container>
	// 	typename std::enable_if<!std::is_same<U, std::list<T>>::value>::type push(const T& value)
	// 	{
	// 		std::stack<T, Container>::push(value);
	// 	}
	// 	// Universal Pop Method
	// 	template <typename U = Container>
	// 	typename std::enable_if<std::is_same<U, std::list<T>>::value>::type pop()
	// 	{
	// 		this->c.pop_back();
	// 	}
	// 	template <typename U = Container>
	// 	typename std::enable_if<!std::is_same<U, std::list<T>>::value>::type pop()
	// 	{
	// 		std::stack<T, Container>::pop();
	// 	}
#include "MutantStack.tpp" //LAST LINE: END
