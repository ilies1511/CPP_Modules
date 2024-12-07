#include "../Includes/tests_05.hpp"

int	main(void)
{
	printer::Header("TESTS EX02");

	srand(static_cast<unsigned>(time(nullptr)));

	//ALL
	testrunner05::ex02();

	//Individual
	// testrunner05::basicTest_ShrubberyCreationForm();
	// testrunner05::basicTest_RobotomyRequestForm();
	// testrunner05::basicTest_PresidentialPardonForm();
	return (0);
}
