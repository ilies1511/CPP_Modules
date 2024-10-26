/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 23:32:20 by iziane            #+#    #+#             */
/*   Updated: 2024/10/26 23:32:22 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

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
