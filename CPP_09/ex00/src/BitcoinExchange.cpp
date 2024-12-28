#include "BitcoinExchange.hpp"
#include "printer.hpp"

//OCF -- BEGIN
BitcoinExchange::BitcoinExchange(const std::string& filename)
	: _dataBase(), _size(0), _DataBaseFile(DATABASE_FILE), _InputFile(filename)
{
	printer::ocf_printer("BitcoinExchange", printer::OCF_TYPE::DNC);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &og)
	: _dataBase(og._dataBase), _size(_dataBase.size()), _DataBaseFile(DATABASE_FILE), _InputFile(og._InputFile)
{
	printer::ocf_printer("BitcoinExchange", printer::OCF_TYPE::CC);
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &og)
{
	if (this != &og)
	{
		printer::ocf_printer("BitcoinExchange", printer::OCF_TYPE::CAC);
		this->_dataBase = og._dataBase;
		this->_size = og._size;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
	printer::ocf_printer("BitcoinExchange", printer::OCF_TYPE::D);
}
//OCF -- END

//Private Helpers
void	BitcoinExchange::fileToMap(void)
{
	std::ifstream database(this->_DataBaseFile);
	if (!database.is_open())
		throw (std::runtime_error("Failed to open Database File"));

	std::string			line;
	int	iter = 0;
	while (getline(database, line))
	{
		std::istringstream iss(line);
		std::string			date;
		std::string			rateStr;
		if (std::getline(iss, date, ',') && std::getline(iss, rateStr))
		{
			try
			{
				long double rate = std::stod(rateStr);
				this->_dataBase[date] = rate; //OG-Syntax: this->_dataBase.insert({date, rate});
			}
			catch (const std::exception &e)
			{
				printer::LogException(e, __FILE__, __FUNCTION__, __LINE__);
				std::cout << coloring("Iteration: " + std::to_string(iter) + ", Line: " + line + "\n", YELLOW);
			}
		}
		else
		{
			std::string error_msg= "Content of " + this->_DataBaseFile + " wrong !";
			throw (std::runtime_error(error_msg));
		}
		iter++;
	}
	database.close();
}

void	BitcoinExchange::printMap(void) const
{
	if (this->_dataBase.empty())
		return ;
	std::map<std::string, long double>::const_iterator it = this->_dataBase.begin();
	while (it != this->_dataBase.end())
	{
		std::cout << "Date: " << it->first;
		std::cout << ", Rate: " << it->second;
		std::cout << "\n";
		++it;
	}
}

long double	BitcoinExchange::getExchangeRat(const std::string& key) const
{
	std::map<std::string, long double>::const_iterator it = this->_dataBase.lower_bound(key);
	if (it == this->_dataBase.begin())
		throw std::out_of_range("Error: bad input => " + key);
	return (it == this->_dataBase.end() || it->first != key) ? std::prev(it)->second : it->second;
}

size_t	BitcoinExchange::getSize(void) const
{
	return (this->_dataBase.size());
}


const std::string&		BitcoinExchange::getInputFile(void) const
{
	return (this->_InputFile);
}

// PARSER -- Begin

/*
	Checks, wether file ends with .txt
	or is in .txt format
*/
bool	BitcoinExchange::checkFileFormat(const std::string& filename) const
{
	if (filename.substr(filename.find_last_of(".") + 1) == "txt")
		return (true);
	std::cerr << "Error: file format is not .txt" << std::endl;
	return (false);
}

/*
	checks wether header is "date | value"
*/
bool	BitcoinExchange::checkHeader(std::ifstream& file) const
{
	std::string	line;
	std::getline(file, line);
	std::istringstream ss(line);
	std::string	header_data, header_pipe, header_value;

	if (!(ss >> header_data >> header_pipe >> header_value))
		return (false);
	if (header_data != "date" || header_pipe != "|" || header_value != "value")
		return (false);
	return (true);
}

bool	BitcoinExchange::checkDate(const long double& year, const long double& month, const long double& day) const
{
	(void)year;
	(void)month;
	(void)day;

	//Check if Number is in Bound
	if (year < 2009 || year > std::numeric_limits<double>::max()
		|| month < 0 || month > 31 || day < 0 || day > 31)
		return (false);
	return (true);
}

bool	BitcoinExchange::checkValue(const long double &value) const
{
	if (value < 0 || value > 1000)
		return (false);
	return (true);
}

/*
	Parser for the Input-File:
		Loop through input file, line by line and call appropriate functs to
		check variables
*/
bool BitcoinExchange::checkInputFile(void) const
{
	int	line_in_inputFile;
	Log	log;
	std::ifstream file(this->_InputFile);

	if (!checkFileFormat(this->_InputFile)) // Datei endet mit .txt
		return (false);
	if (!file.is_open())
		return (false);
	if (!checkHeader(file))
		return (false);
	line_in_inputFile = 1;
	std::string line, stash;
	while (std::getline(file, line))
	{
		//Ignores whitespace Lines
		if (line.empty() || std::all_of(line.begin(), line.end(), ::isspace))
		{
			++line_in_inputFile;
			continue ;
		}

		std::istringstream sstream(line);
		char dash1, dash2, pipe;
		int	year, month, day;
		long double	value;
		++line_in_inputFile;
		if (!(sstream >> year >> dash1 >> month >> dash2 >> day >> pipe >> value))
		{
			std::cout << coloring ("Line in input file: " + std::to_string(line_in_inputFile), PURPLE) << "\n";
			log.complain("ERROR", "Bad Input (line not in the right format)\n" + line, __FILE__, __FUNCTION__, __LINE__);
			return (false);
		}
		if (dash1 != '-' || dash2 != '-' || pipe != '|')
		{
			std::cout << coloring ("Line in input file: " + std::to_string(line_in_inputFile), PURPLE) << "\n";
			log.complain("ERROR", "Bad Input ('-', '|')\n" + line, __FILE__, __FUNCTION__, __LINE__);
			return (false);
		}
		if (!checkDate(year, month, day))
		{
			std::cout << coloring ("Line in input file: " + std::to_string(line_in_inputFile), PURPLE) << "\n";
			log.complain("ERROR", "Bad Input\n" + line, __FILE__, __FUNCTION__, __LINE__);
			return (false);
		}
		if (!checkValue(value))
		{
			std::cout << coloring ("Line in input file: " + std::to_string(line_in_inputFile), PURPLE) << "\n";
			log.complain("ERROR", "Wrong Value\n" + line, __FILE__, __FUNCTION__, __LINE__);
			return (false);
		}
	}
	return (true);
}
// PARSER -- END


