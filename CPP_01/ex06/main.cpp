#include "Harl.hpp"
#include "log.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		print_log(INFO, "Usage: ./filter <status_log> (ERROR, WARNING, DEBUG, INFO)");
		return (0);
	}

	Harl	harl;
	harl.complain(argv[1]);
	return (0);
}
