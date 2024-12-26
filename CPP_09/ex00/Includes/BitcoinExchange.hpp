#pragma once

//Includes
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
	//Helpers
	private:
	//OCF
	public:
		BitcoinExchange(const std::string& filename);
		BitcoinExchange(const BitcoinExchange &og);
		BitcoinExchange &operator=(const BitcoinExchange &og);
		~BitcoinExchange(void);
	//Members-HelperFNCs
	public:
		//getters
		void				fileToMap(void);
		void				printMap(void) const;
		size_t				getSize(void) const;
		const	long double	&getValue(std::string key) const; //only read access
		long double			&getValue(std::string key); //read & write access
};
