/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:50:36 by iziane            #+#    #+#             */
/*   Updated: 2024/12/22 04:24:56 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Tests/test.hpp"
#include "MutantStack.hpp"
#include <random>
#include <ctime>
#include <string>

// #include "test.hpp"

//IMPLEMENTATION
namespace testrunner
{
	void	test_subj_deque(void)
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	void	list(void)
	{
		MutantStack<int, std::list<int>> mstack;

		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int,std::list<int>>::iterator it = mstack.begin();
		MutantStack<int, std::list<int>>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << "Loop\n";
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int, std::list<int>> s(mstack);
	}
} //	 namespace testrunnner
