#ifndef SED_HPP
#define SED_HPP

//Includes
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class Sed
{
	private:
		std::string filename;
		std::string s1;
		std::string s2;
		std::ifstream infile;
		std::ofstream outfile;
		// Private helper functions for parsing
		bool validate_input();
		bool open_input_file();
		bool is_file_empty();
		bool does_string_exist();
		bool open_output_file();
	public:
		Sed(const std::string& filename, const std::string& search, const std::string& replacer) : filename(filename), s1(search), s2(replacer){};
		~Sed(){file_closer();};
		bool parser();
		bool do_sed();
		void file_closer();
		bool routine();
};

#endif
