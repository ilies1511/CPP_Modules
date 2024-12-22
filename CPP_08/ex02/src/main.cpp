/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:47:28 by iziane            #+#    #+#             */
/*   Updated: 2024/12/22 16:32:52 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Tests/test.hpp"
#include "../Includes/Extra/printer.hpp"
#include "MutantStack.hpp"
#include <list>
#include <forward_list>

// cp -r ex00 ex01
int	main(void)
{
	/*
		Leaks Check:
			dorker valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ex03.out
	*/
	printer::Header("TESTS CPP08 EX01");

	printer::Header("Container Deque");
	testrunner::list();
	printer::Header("Container List");
	testrunner::test_subj_deque();
	printer::Header("Container Vector");
	testrunner::test_subj_vector();
	testrunner::test_subj_vector();
	printer::Header("FULL Vector No MutantStack");
	testrunner::test_fullVec();
	return (0);
}


/*
	List Code Test:
		printer::Header("TESTS CPP08 EX01");

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
	// MutantStack<int>::iterator it = mstack.begin();
	// MutantStack<int>::iterator ite = mstack.end();
	MutantStack<int, std::list<int>>::iterator it = mstack.begin();
	MutantStack<int, std::list<int>>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	// std::stack<int> s(mstack);
	    // Copy MutantStack into a regular std::stack
    std::stack<int, std::list<int>> s(mstack);
	return (0);
*/
