#include "../Includes/Point.hpp"

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

/*
	BSP = Binary space partitioning
	orients[0] = orient_abp;
	orients[1] = orient_bcp;
	orients[2] = orient_cap;
*/
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	orients[3];

	orients[0] = calculate_orient(a, b, point);
	orients[1] = calculate_orient(b, c, point);
	orients[2] = calculate_orient(c, a, point);
	return (interpretation_of_orients(orients));
}


