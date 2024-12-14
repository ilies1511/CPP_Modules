#include "test.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main(void)
{
	printer::Header("TESTS");
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	// testrunner::randomGenerator();
	Base *res = new Base;

	res = generate();
	identifyBy_ptr(res);
	identifyBy_ref(*res);
	return (0);
}
