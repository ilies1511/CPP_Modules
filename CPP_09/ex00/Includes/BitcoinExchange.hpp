#pragma once

//Includes
#include <iomanip> //Precision
#include <stdbool.h> //Bool
#include <limits>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>
#include <limits>
#include <deque>
#include <stack>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <regex>

#ifndef DATABASE_FILE
# define DATABASE_FILE "data.csv"
#endif

//Own
#include "printer.hpp"

//Class

class BitcoinExchange
{
	//Attributes
	private:
		std::map<std::string, long double>	_dataBase; //_storeFiles.insert("alo", 2);
		size_t								_size;
		const std::string					_DataBaseFile;
		const std::string					_InputFile;
	//OCF
	public:
		BitcoinExchange(const std::string& filename);
		BitcoinExchange(const BitcoinExchange &og);
		BitcoinExchange &operator=(const BitcoinExchange &og);
		~BitcoinExchange(void);
	//Members-HelperFNCs -- BEGIN
	private:
		bool				checkHeader(std::ifstream& file) const;
		bool				checkFileFormat(const std::string& filename) const;
		bool				checkDate(int& year, int& month, int& day) const;
		bool				checkValue(const long double &value) const;
		bool				checkLine(const std::string &line, int *line_in_inputFile) const;
		bool				preContentCheck(std::ifstream& file) const; // Calls checkHeader(), checkFileFormat(),
	public:
		//Helpers
		void				fileToMap(void);
		long double			getExchangeRat(const std::string& key) const;
		void				printMap(void) const;
		bool				checkInputFile(void) const; //Entry Point for Parser
		//getters
		size_t				getSize(void) const;
		const std::string&	getInputFile(void) const;
	//Members-HelperFNCs -- END
};


	// const	long double	&getValue(std::string key) const; //only read access
	// long double			&getValue(std::string key); //read & write access
