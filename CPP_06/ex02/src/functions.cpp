#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

//Members--BEGIN
Base * generate(void)
{
	size_t	x;

	x = 1 + static_cast<unsigned int>(std::rand()) / ((RAND_MAX + 1u) / 3);

	switch (x)
	{
	case 1:
		return (new A());
	case 2:
		return (new B());
	case 3:
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

void identify(Base* p)
{
	(void)p;
	std::cout << "In identify 1\n";
}

void identify(Base& p)
{
	(void)p;
	std::cout << "In identify 2\n";
}
//Members--END


