/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:50:36 by iziane            #+#    #+#             */
/*   Updated: 2024/12/22 16:46:26 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Tests/test.hpp"
#include "MutantStack.hpp"
#include <random>
#include <ctime>
#include <forward_list>
#include <string>

// #include "test.hpp"

//IMPLEMENTATION
namespace testrunner
{
	void	test_fullVec(void)
	{
		try
		{
			std::vector<int> vec;

			vec.push_back(5);
			vec.push_back(17);
			std::cout << vec.at((vec.size() - 1)) << std::endl;
			vec.pop_back();
			std::cout << vec.size() << std::endl;
			vec.push_back(3);
			vec.push_back(5);
			vec.push_back(737);
			//[...]
			vec.push_back(0);
			std::vector<int>::iterator it = vec.begin();
			std::vector<int>::iterator ite = vec.end();
			++it;
			--it;
			while (it != ite)
			{
				std::cout << *it << std::endl;
				++it;
			}
		}
		catch (const std::exception &e)
		{
			printer::LogException(e, __FILE__, __FUNCTION__, __LINE__);
		}
	}

	void	test_subj_deque(void)
	{
		try
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
		catch(const std::exception& e)
		{
			printer::LogException(e, __FILE__, __FUNCTION__, __LINE__);
		}
	}

	void	test_subj_vector(void)
	{
		try
		{
			MutantStack<int, std::vector<int>> mstack;

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
			MutantStack<int, std::vector<int> >::iterator it = mstack.begin();
			MutantStack<int, std::vector<int> >::iterator ite = mstack.end();
			++it;
			while (it != ite)
			{
				std::cout << *it << std::endl;
				++it;
			}
			std::stack<int, std::vector<int>> s(mstack);
		}
		catch(const std::exception& e)
		{
			printer::LogException(e, __FILE__, __FUNCTION__, __LINE__);
		}
	}

	void	list(void)
	{
		try
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
		catch(const std::exception& e)
		{
			printer::LogException(e, __FILE__, __FUNCTION__, __LINE__);
		}
	}
} //	 namespace testrunnner
