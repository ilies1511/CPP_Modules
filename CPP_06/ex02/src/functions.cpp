#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "../Extra/printer.hpp"
#include <random>


//Members--BEGIN
Base * generate(void)
{
	static std::random_device rd;
	static std::mt19937 generator(rd());
	static std::uniform_int_distribution<int> distrib(1, 3);

	int x = distrib(generator);

	/*
		Alte Version:
			size_t	x;
			x = 1 + static_cast<unsigned int>(std::rand()) / ((RAND_MAX + 1u) / 3);
	*/

	switch (x)
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
	if (!p)
		std::cout << "Pointer points to NULL\n";
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
}

void identifyBy_ref(Base& p)
{
	std::cout << coloring("In Identify (by Reference): ", PURPLE);
	try
	{
		static_cast<void>(dynamic_cast<A&>(p));// Same but is C Way of typeCasting (size_t)x: (void)dynamic_cast<B&>(p);
		std::cout << "A\n";
		return ;
	}
	catch (const std::bad_cast& e) {}
	try
	{
		static_cast<void>(dynamic_cast<B&>(p));
		std::cout << "B\n";
		return ;
	}
	catch (const std::bad_cast& e) {}
	try
	{
		static_cast<void>(dynamic_cast<C&>(p));
		std::cout << "C\n";
		return ;
	}
	catch (const std::bad_cast& e)
	{
		std::cout << "Un-registered subclass of Base class\n";
		printer::LogException(e, __FILE__ , __FUNCTION__, __LINE__);
	}
}
//Members--END


