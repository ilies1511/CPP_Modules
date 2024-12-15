/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:50:36 by iziane            #+#    #+#             */
/*   Updated: 2024/12/15 14:57:21 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Tests/test.hpp"

//IMPLEMENTATION
namespace testrunner
{
	void randomGenerator(void)
	{
		size_t	x;
		size_t	c1 = 0;
		size_t	c2 = 0;
		size_t	c3 = 0;

		for (int i = 0; i < 90000; i++)
		{
			x = 1 + static_cast<unsigned int>(std::rand()) / ((RAND_MAX + 1u) / 3);
			if (x == 1){c1++;}
			else if (x == 2){c2++;}
			else if (x == 3){c3++;}
			std::cout << "x: " << x << "\n";
			// Note: 1 + rand() % sides is biased
		}
		std::cout << "Amount of 1: " << c1 << " --> " << (static_cast<long double>(c1)/90000) * 100 << "%\n";
		std::cout << "Amount of 2: " << c2 << " --> " << (static_cast<long double>(c2)/90000) * 100 << "%\n";
		std::cout << "Amount of 3: " << c3 << " --> " << (static_cast<long double>(c3)/90000) * 100 << "%\n";
	}

	void	ex02(void)
	{
		printer::Header("TEST EX02");
		Base *res;

		res = generate();
		identifyBy_ptr(res);
		identifyBy_ref(*res);

		delete (res);
	}

	void	ex02_unregistered_subclass(void)
	{
		printer::Header("TEST unregistered_subclass");
		Base* normal = new Base;

		identifyBy_ptr(normal);
		identifyBy_ref(*normal);

		delete (normal);
	}

	void	ex02_Childs(void)
	{
		printer::Header("TEST EX03");
		Base *child_A = new A;
		Base *child_B = new B;
		Base *child_C = new C;

		printer::Header("Child A");
		identifyBy_ptr(child_A);
		identifyBy_ref(*child_A);
		printer::Header("Child B");
		identifyBy_ptr(child_B);
		identifyBy_ref(*child_B);
		printer::Header("Child C");
		identifyBy_ptr(child_C);
		identifyBy_ref(*child_C);
		delete (child_A);
		delete (child_B);
		delete (child_C);
	}

} // namespace testrunnner
