#include "log.hpp"
#include "sed.hpp"

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
	size_t		found_pos = 0;

	if (filename.empty() || s1.empty() || s2.empty())
	{
		print_log(ERROR, "Can't work with string being NULL");
		return ;
	}
	if (!s1.compare(s2))
		return (print_log(INFO, "s1 and s2 exactly the same"));
	std::ifstream infile (filename);
	if (!infile)
	{
		print_log(ERROR, "Error opening infile");
		return ;
	}
	std::ofstream outfile (filename + ".replace");
	if (!outfile)
	{
		print_log(ERROR, "Error opening outfile");
		return ;
	}
	while (std::getline(infile, line))
	{
		found_pos = 0;
		while (true)
		{
			found_pos = line.find(s1, found_pos);
			if (found_pos == std::string::npos)
				break ;
			line.erase(found_pos, s1.length());
			line.insert(found_pos, s2);
			found_pos = found_pos + s2.length();
		}
		outfile << line << "\n";
		/* TODO:
		Add error Check:
			outfile.bad();
			outfile.fail();
		*/
	}
	outfile.close();
	infile.close();
	print_log(INFO, filename + ".replace file created");
	return ;
}

bool	parser(int argc, char **argv)
{
	(void)argv;
	if (argc != 4)
		return (print_log(ERROR, "Enter valid amount of args"), false);

	return (true);
}

int	main(int argc, char **argv)
{
	if (parser(argc, argv))
		copy_content(static_cast<std::string>(argv[1]), \
			static_cast<std::string>(argv[2]), static_cast<std::string>(argv[3]));
	else
		return (print_log(ERROR, "Parser Error"), 1);
	return (print_log(SUCCESS, "Successful execution"), 0);
}
