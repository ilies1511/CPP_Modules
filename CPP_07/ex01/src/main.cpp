/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:47:28 by iziane            #+#    #+#             */
/*   Updated: 2024/12/15 20:24:32 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Tests/test.hpp"
#include "iter.hpp"

void	addOne(int &x)
{
	x += 1;
}

int	main(void)
{
	/*
		Leaks Check:
			dorker valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ex03.out
	*/
	printer::Header("TESTS CPP07");
	testrunner::arrayXtemplate();
	return (0);
}
