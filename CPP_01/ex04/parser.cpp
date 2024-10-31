#include "sed.hpp"
#include "log.hpp"

bool Sed::open_output_file()
{
	outfile.open(filename + ".replace");
	if (!outfile.is_open())
		return (infile.close(), print_log(ERROR, "Error creating output file"), false);
	return (true);
}

bool Sed::does_string_exist()
{
	std::string line;
	bool found = false;

	// infile.seekg(0, std::ios::beg);
	while (std::getline(infile, line))
	{
		if (line.find(s1) != std::string::npos)
		{
			found = true;
			break;
		}
	}
	if (!found)
	{
		print_log(INFO, "The string '" + s1 + "' was not found in the file.");
		infile.close();
		return (false);
	}
	infile.clear();
	infile.seekg(0, std::ios::beg);
	return (true);
}

bool Sed::is_file_empty()
{
	bool res = true;
	infile.seekg(0, std::ios::end);
	if (infile.tellg() == 0)
	{
		print_log(INFO, "The input file is empty; nothing to process.");
		infile.close();
		res = false;
	}
	infile.clear();
	infile.seekg(0, std::ios::beg);
	return (res);
}

bool Sed::open_input_file()
{
	infile.open(filename);
	if (!infile.is_open())
		return(print_log(ERROR, "Error opening input file"), false);
	return (true);
}

bool Sed::validate_input()
{
	if (filename.empty() || s1.empty() || s2.empty())
	{
		print_log(ERROR, "Can't work with string being NULL");
		return (false);
	}
	if (!s1.compare(s2))
		return (print_log(INFO, "s1 and s2 exactly the same"), false);
	return (true);
}

bool Sed::parser()
{
	if (!validate_input())
		return (false);
	if (!open_input_file())
		return (false);
	if (!is_file_empty())
		return (false);
	if (!does_string_exist())
		return (false);
	if (!open_output_file())
		return (false);
	return (true);
}





// Workin version, but not clean
// bool Sed::parser()
// {
// 	if (filename.empty() || s1.empty() || s2.empty())
// 	{
// 		print_log(ERROR, "Can't work with string being NULL");
// 		return (false);
// 	}
// 	if (!s1.compare(s2))
// 		return (print_log(INFO, "s1 and s2 exactly the same"), false);
// 	infile.open(filename);
// 	if (!infile.is_open())
// 		return(print_log(ERROR, "Error opening input file"), false);
// 	infile.seekg(0, std::ios::end);
// 	if (infile.tellg() == 0)
// 	{
// 		print_log(INFO, "The input file is empty; nothing to process.");
// 		infile.close();
// 		return (false);
// 	}
// 	infile.seekg(0, std::ios::beg);
// 		// Check if s1 exists in the file
// 	std::string line;
// 	bool found = false;
// 	while (std::getline(infile, line))
// 	{
// 		if (line.find(s1) != std::string::npos)
// 		{
// 			found = true;
// 			break;
// 		}
// 	}
// 	if (!found)
// 	{
// 		print_log(INFO, "The string '" + s1 + "' was not found in the file.");
// 		infile.close();
// 		return false;
// 	}
// 	infile.clear();
// 	infile.seekg(0, std::ios::beg);
// 	outfile.open(filename + ".replace");
// 	if (!outfile.is_open())
// 		return (infile.close(), print_log(ERROR, "Error creating output file"), false);
// 	return (true);
// }
