#include "log.hpp"
#include "sed.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		print_log(ERROR, "Usage: <filename> <search_string> <replace_string>");
		return (1);
	}
	Sed canon(argv[1], argv[2], argv[3]);
	if (!(canon.routine()))
		return (1);
	return (print_log(SUCCESS, "Successful execution"), 0);
}
