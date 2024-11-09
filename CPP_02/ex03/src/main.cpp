// #include "Fixed.hpp"
#include "../Includes/Point.hpp"

int main(void)
{
	std::cout << "TESTS\n\n";
	Point const	a1(0, 0), b1(0, 1), c1(0, 3);

	Point const	points[] =
	{
		Point(1.0f, 1.0f),
		Point(0.2f, 0.2f),
		Point(0.6f, 0),
		Point(0.6f, 0.1f),
		Point(-0.6f, 0.1f),
		Point(0.3f, 0.6f),
		Point(0.2f, 1.0f),
		Point(0.9f, 0.1f),
		Point(0.9f, 0.05f),
		Point(0.2f, 0.7f),
		Point(0, 0),
		Point(0, 1)
	};
	for (int i = 0; static_cast<unsigned long>(i) < (sizeof(points) / sizeof(points[0])); i++)
		bsp(a1, b1, c1, points[i]);
	return (0);
}
