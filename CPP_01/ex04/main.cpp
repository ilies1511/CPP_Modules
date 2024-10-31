#include "log.hpp"

void	print_outfile(const std::string finished_oufile)
{
	std::string line;

	std::ifstream infile (finished_oufile);
	if (!infile)
	{
		print_log(ERROR, "failed to open finished_outfile");
		return ;
	}
	while (getline(infile, line))
	{
		getline(infile, line);
		std::cout << line;
	}
	infile.close();
}

void	copy_content(const std::string& filename, \
			const std::string& s1, const std::string& s2)
{
	std::string line;
	std::string location;

	if (filename.empty() || s1.empty() || s2.empty())
	{
		print_log(ERROR, "Can't work with string being NULL");
		exit(1);
	}
	std::ifstream infile (filename);
	if (!infile)
	{
		print_log(ERROR, "Error opening infile");
		return ;
	}
	std::ofstream outfile (filename + ".replace");
	while (getline(infile, line))
		outfile << line + "\n";
	outfile.close();
	return ;
}

int	main(int argc, char **argv)
{
	if (argc < 4)
		return (print_log(ERROR, "Enter valid amount of args"), 0);
	copy_content(static_cast<std::string>(argv[1]), \
		static_cast<std::string>(argv[2]), static_cast<std::string>(argv[3]));
	return (0);
}
