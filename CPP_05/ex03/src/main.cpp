#include "../Includes/tests_05.hpp"

/*
		Leaks Check:
			dorker valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ex03.out
*/
int	main(void)
{

	srand(static_cast<unsigned>(time(nullptr)));

	//ALL
	printer::Header("TESTS EX02");
	testrunner05::ex02();
	printer::Header("TESTS EX03");
	testrunner05::ex03();
	return (0);
}
