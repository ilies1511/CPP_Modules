/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 23:32:20 by iziane            #+#    #+#             */
/*   Updated: 2024/10/27 15:33:12 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*
	Blueprint Lambda function in C++:
	[capture list] (parameter list) -> return type { function body };
	- []: tracks variables outside the lambda fnc, if empty: no extern var. used
	- (param list): fnc. accepts 'unsigned char'
	- return type: optional since compiler is doing it autom.
		in this case: return type ==> unsigned char
	- { function }

	std::transform:
		1. arg: start point: str.begin().
		2. arg: end point: str.end().
		3. arg: where to write/'store'
		4. arg: Lambda Function: gets called for every char.

	==> In summary, the lambda function converts each character to uppercase
		individually, while std::transform ensures that this function is
		applied to each character.
*/

std::string str_toupper(std::string str)
{
	std::transform(str.begin(), str.end(), str.begin(),
		[](unsigned char c){ return std::toupper(c);});
	return (str);
}

static void	megaphone(std::string str)
{
	std:: cout << str_toupper(str);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		megaphone("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
	else
	{
		for (int i = 1; i < (argc); i++)
			megaphone(argv[i]);
	}
	std::cout << '\n';
	return (0);
}
