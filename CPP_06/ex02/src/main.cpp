#include "../Includes/Tests/test.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main(void)
{
	/*
		Leaks Check:
			dorker valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ex03.out
	*/
	printer::Header("TESTS");
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	testrunner::randomGenerator();
	testrunner::ex02();
	testrunner::ex02_unregistered_subclass();

	testrunner::ex02_Childs();
	return (0);
}
