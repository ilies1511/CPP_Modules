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
	public:
		Sed(const std::string& filename, const std::string& search, const std::string& replacer) : filename(filename), s1(search), s2(replacer){};
		~Sed(){file_closer();};
		bool parser();
		bool do_sed();
		void file_closer();
		bool routine();
};

#endif
