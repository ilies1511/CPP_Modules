/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:50:36 by iziane            #+#    #+#             */
/*   Updated: 2024/12/15 22:02:03 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Tests/test.hpp"
// #include "test.hpp"
#include "iter.hpp"

/*
	Needed to print 't_data ownType[]' via cout
*/
std::ostream& operator<<(std::ostream& os, const t_data& data)
{
os << "ID: " << data.i << ", Name: " << data.name;
return (os);
}

//IMPLEMENTATION
namespace testrunner
{
	// Log	status;
	void	arrayXtemplate(void)
	{
		int		intArray[] = {99, 9, 92, 23, 232, 2};
		char	charArray[] = {'O','u', 'e', 'y', 'Z', 'i', 'z', 'o', 'u'};
		char	cStyle[] = "Ouey Zizou";
		printer::Header("\nintArray");
		iter(intArray, sizeof(intArray) / sizeof(intArray[0]), printElement<int>);
		printer::Header("\ncharArray");
		iter(charArray, sizeof(charArray) / sizeof(charArray[0]), printElement<char>);
		printer::Header("\ncStyle");
		iter(cStyle, sizeof(cStyle) / sizeof(cStyle[0]), printElement<char>);
	}

	void	ownDataType(void)
	{
		t_data ownType[] =
		{
			{1, "Sah'ween"},
			{2, "Gwyneth"},
			{3, "Meikel"}
		};
		iter(ownType, sizeof(ownType) / sizeof(ownType[0]), printElement<t_data>);
	}

	void	adder(void)
	{
		int		intArray[] = {99, 9, 92, 23, 232, 2};
		char	cStyle[] = "Ouey Zizou";

		printer::Header("[ADDER - INT]: PRE ITER");
		iter(intArray, sizeof(intArray) / sizeof(intArray[0]), printElement<int>);
		printer::Header("[ADDER]: POST ITER");
		iter(intArray, sizeof(intArray) / sizeof(intArray[0]), addOne<int>);
		iter(intArray, sizeof(intArray) / sizeof(intArray[0]), printElement<int>);

		printer::Header("[ADDER - CHAR]: PRE ITER");
		printer::Header("[ADDER]: PRE ITER");
		iter(cStyle, sizeof(cStyle) / sizeof(cStyle[0]), printElement<char>);
		printer::Header("[ADDER]: POST ITER");
		iter(cStyle, sizeof(cStyle) / sizeof(cStyle[0]), addOne<char>);
		iter(cStyle, sizeof(cStyle) / sizeof(cStyle[0]), printElement<char>);
	}

} // namespace testrunnner
