/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 23:39:07 by iziane            #+#    #+#             */
/*   Updated: 2024/11/09 23:39:08 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Point.hpp"

/*
	Cross-Product Approach for Determining Point Position Relative to a Triangle

	The cross-product method helps calculate the orientation between vectors
	that form the sides of the triangle and the point in question, without
	actually calculating angles. This approach is highly efficient and widely
	used to determine if a point lies inside or outside a triangle.

	Step-by-Step Explanation:

	1. **Defining the Vectors**:
		- Given the vertices of the triangle A, B, and C, and the point P whose
		position relative to the triangle we want to determine.
		- We consider the vectors AB, BC, and CA that form the sides of the
		triangle, and the vectors AP, BP, and CP that point from the triangle
		vertices to the point P.

	2. **Using the Cross-Product for Orientation**:
		- To determine the orientation, we calculate the cross-product
			between the following vectors:
			- Orient_ABP = (B - A) × (P - A)
			- Orient_BCP = (C - B) × (P - B)
			- Orient_CAP = (A - C) × (P - C)
		- Each of these cross-products gives a scalar that indicates the
		orientation of the point P relative to the respective side of the triangle:
			- If the cross-product is **positive**, point P lies **counterclockwise** to the triangle side.
			- If the cross-product is **negative**, point P lies **clockwise** to the triangle side.
			- If the cross-product is **zero**, point P lies on the line of the triangle side.

	3. **Interpreting the Cross-Product Results**:
		- To decide whether point P lies inside the triangle, we examine the signs of the three computed cross-products:
		- Point P lies inside the triangle if **all three cross-products have the same sign** (either all positive or all negative). This means that the orientation of the angles is consistent (all counterclockwise or all clockwise).
		- If the cross-products have different signs, point P lies **outside** the triangle.

	Example Calculation:

	Given the coordinates:
		- A = (x_A, y_A)
		- B = (x_B, y_B)
		- C = (x_C, y_C)
		- P = (x_P, y_P)

	The cross-product of vectors AB and AP is:
		Orient_ABP = (x_B - x_A)(y_P - y_A) - (y_B - y_A)(x_P - x_A)

	Similarly, for the other sides:
		Orient_BCP = (x_C - x_B)(y_P - y_B) - (y_C - y_B)(x_P - x_B)
		Orient_CAP = (x_A - x_C)(y_P - y_C) - (y_A - y_C)(x_P - x_C)

	The signs of these cross-products determine whether the point lies inside or outside the triangle, without the need to calculate actual angles.
*/


//Checks if Point lies in on edge
bool	check_if_on_edge(Fixed orients[3])
{
	if (orients[0] == 0)
		return (std::cout << coloring("Point lies on the AB edge\n", RED), false);
	if (orients[1] == 0)
		return (std::cout << coloring("Point lies on the BC edge\n", RED), false);
	if (orients[2] == 0)
		return (std::cout << coloring("Point lies on the CA edge\n", RED), false);
	return (std::cout << coloring("Point INSIDE\n", GREEN), true);
}
/*
	Checks if the orients have the same Vorzeichen
	true = point in the trinagle
	false = point not in triagle
*/
bool	interpretation_of_orients(Fixed orients[3])
{
	bool	allPositve = orients[0] >= 0 && orients[1] >= 0 && orients[2] >= 0;
	bool	allNegative = orients[0] <= 0 && orients[1] <= 0 && orients[2] <= 0;

	if (allPositve || allNegative)
		return (check_if_on_edge(orients));
	return (std::cout << coloring("Point OUTSIDE\n", RED), false);
}

//calculate orientation using Crossproduct:
// Fixed	calculate_orient(Point const &vertice1, Point const &vertice2, Point const &point)
Fixed	calculate_orient(Point const &vertice1, Point const &vertice2, Point const &p)
{
	return (vertice2.getX() - vertice1.getX()) * (p.getY() - vertice1.getY()) -
		(vertice2.getY() - vertice1.getY()) * (p.getX() - vertice1.getX());
}

bool	is_valid_triagel(Point const &a, Point const &b, Point const &c)
{
	Fixed crossproduct;

	crossproduct = calculate_orient(a, b, c);
	if (crossproduct == 0)
		return (std::cout << coloring("[ERROR]: Points are collinear. Not a valid triangle\n", RED), false);
	return (true);
}

/*
	BSP = Binary space partitioning
	orients[0] = orient_abp;
	orients[1] = orient_bcp;
	orients[2] = orient_cap;
*/
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	orients[3];

	if (!is_valid_triagel(a, b, c))
		return (false);
	orients[0] = calculate_orient(a, b, point);
	orients[1] = calculate_orient(b, c, point);
	orients[2] = calculate_orient(c, a, point);
	return (interpretation_of_orients(orients));
}


