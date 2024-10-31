#include "sed.hpp"
#include "log.hpp"

void Sed::file_closer()
{
	if (infile.is_open())
		infile.close();
	if (outfile.is_open())
		outfile.close();
}

bool Sed::do_sed()
{
	std::string line;
	size_t		found_pos = 0;

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
		if (outfile.bad() || outfile.fail())
		{
			return (print_log(ERROR, "Error writing to output file"), false);
		}
	}
	return (print_log(INFO, filename + ".replace file created successfully"), true);
}

bool Sed::routine()
{
	if (!parser())
		return (false);
	if (!do_sed())
		return (false);
	return (true);
}
