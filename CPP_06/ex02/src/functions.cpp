#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

//Members--BEGIN
Base * generate(void)
{
	size_t	x;

	x = 1 + static_cast<unsigned int>(std::rand()) / ((RAND_MAX + 1u) / 3);

	switch (1 + static_cast<unsigned int>(std::rand()) / ((RAND_MAX + 1u) / 3))
	{
	case 1:
		std::cout << "Retured A\n";
		return (new A());
	case 2:
		std::cout << "Retured B\n";
		return (new B());
	case 3:
		std::cout << "Retured C\n";
		return (new C());
	default:
		return (nullptr);
	}
	// if (x == 1)
	// 	return (new (A));
	// else if (x == 2)
	// 	return (new (B));
	// else if (x == 3)
	// 	return (new (C));
}

void identifyBy_ptr(Base* p)
{
	std::cout << coloring("In Identify (by Pointer): ", PURPLE);
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
}

void identify(Base& p)
{
	(void)p;
	std::cout << "In identify 2\n";
}
//Members--END


