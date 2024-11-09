// #include "Fixed.hpp"
#include "../Includes/Point.hpp"

int main(void)
{
	std::cout << "TESTS\n";
	Point const	a1(0, 0), b1(0, 1), c1(0, 3);

	Point const	point1(1.0f, 1.0f);
	Point const	point2(0.2f, 0.2f);
	Point const	point3(0.6f, 0);
	Point const	point4(0.6f, 0.1f);
	Point const	point5(-0.6f, 0.1f);
	Point const	point6(0.3f, 0.6f);
	Point const	point7(0.2f, 1.0f);
	Point const	point8(0.9f, 0.1f);
	Point const	point9(0.9f, 0.05f);
	Point const	point10(0.2f, 0.7f);
	Point const	point11(0, 0);
	Point const	point12(0, 1);
	bsp(a1, b1, c1, point1);
	bsp(a1, b1, c1, point2);
	bsp(a1, b1, c1, point3);
	bsp(a1, b1, c1, point4);
	bsp(a1, b1, c1, point5);
	bsp(a1, b1, c1, point6);
	bsp(a1, b1, c1, point7);
	bsp(a1, b1, c1, point8);
	bsp(a1, b1, c1, point9);
	bsp(a1, b1, c1, point10);
	bsp(a1, b1, c1, point11);
	bsp(a1, b1, c1, point12);
	return (0);
}
