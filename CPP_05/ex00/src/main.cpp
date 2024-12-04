#include "tests_05.hpp"

int	main(void)
{
	printer::Header("BASIC TESTS");
	testrunner05::basic_test();
	printer::Header("BASIC2 TESTS");
	testrunner05::basic2_test();
	printer::Header("BASIC_PLUS TESTS");
	testrunner05::basic_plus_test();
	printer::Header("DECREMENT TEST");
	testrunner05::decrementGrade();
	printer::Header("INCREMENT TEST");
	testrunner05::incrementGrade();
	printer::Header("CopyConstructor TEST");
	testrunner05::ocf_copyConstructor();
	printer::Header("Copy Assignment TEST");
	testrunner05::ocf_copyAssignment();
	return (0);
}
