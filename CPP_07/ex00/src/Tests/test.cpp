/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:50:36 by iziane            #+#    #+#             */
/*   Updated: 2024/12/15 19:28:32 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Tests/test.hpp"

//IMPLEMENTATION
namespace testrunner
{
	Log	status;
	int	subj_TEST(void)
	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		//SOLL-CHECK
		if (a != 3 || b != 2)
		{
			status.complain("ERROR", "Swap - Int", __FILE__, __FUNCTION__, __LINE__);
			return (EXIT_FAILURE);
		}
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		if (::min( a, b ) != 2)
		{
			status.complain("ERROR", "MIN - Int", __FILE__, __FUNCTION__, __LINE__);
			return (EXIT_FAILURE);
		}
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		if (::max( a, b ) != 3)
		{
			status.complain("ERROR", "MAX - Int", __FILE__, __FUNCTION__, __LINE__);
			return (EXIT_FAILURE);
		}
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		if (c != "chaine2" || d != "chaine1")
		{
			status.complain("ERROR", "swap - Strings", __FILE__, __FUNCTION__, __LINE__);
			return (EXIT_FAILURE);
		}
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		if (::min( c, d ) != "chaine1")
		{
			status.complain("ERROR", "MIN - Strings", __FILE__, __FUNCTION__, __LINE__);
			return (EXIT_FAILURE);
		}
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
		if (::max( c, d ) != "chaine2")
		{
			status.complain("ERROR", "MAX - Strings", __FILE__, __FUNCTION__, __LINE__);
			return (EXIT_FAILURE);
		}
		std::cout << coloring("SUCCESS ! All tests passed\n", GREEN);
		return (EXIT_SUCCESS);
	}
} // namespace testrunnner
