#include "tests_05.hpp"

int	main(void)
{
	printer::Header("BASIC TESTS");
	testrunner05::basic_test();
	testrunner05::basic_plus_test();
	printer::Header("DECREMENT TEST");
	testrunner05::decrementGrade();
	printer::Header("INCREMENT TEST");
	testrunner05::incrementGrade();
	return (0);
}
