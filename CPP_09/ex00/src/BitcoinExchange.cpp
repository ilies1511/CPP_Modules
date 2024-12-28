#include "BitcoinExchange.hpp"
#include "printer.hpp"
#include "Log.hpp"

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
	Valid Header: "date | value"
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

/*
	Valid Date: YYYY-MM-DD (Format)
				Year:	present and before
				Moth:	01-12
				Day:	01-31, + Leap Year Check + February (28/29)
*/
bool	BitcoinExchange::checkDate(int &year, int &month, int &day) const
{
	if (year < 2009 || year > std::numeric_limits<double>::max()
		|| month < 1 || month > 12 || day < 1 | day > 31)
		return (false);

	//Init tm-Struct (ctime lib)
	struct tm t = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	t.tm_year = year - 1900;
	t.tm_mon = month - 1; //(0 - 11)
	t.tm_mday = day;

	//Appling t on function mktime()
	if (mktime(&t) == -1)
		return (false);

	//Check if Date is in Future
	time_t now = time(nullptr);
	struct tm *now_tm = localtime(&now);
	if (now_tm->tm_year < t.tm_year
		|| (now_tm->tm_year == t.tm_year && now_tm->tm_mon < t.tm_mon) ||
			(now_tm->tm_year == t.tm_year && now_tm->tm_mon == t.tm_mon
				&& now_tm->tm_mday < t.tm_mday))
		return (false);

	//Leap Year Check
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
		daysInMonth[1] = 29; // Schaltjahr
	if (day > daysInMonth[month - 1])
		return (false);
	return (true);
}

/*
	Valid Value: either a float or positive integer, between 0 and 1000
*/
bool	BitcoinExchange::checkValue(const long double &value) const
{
	std::cout << "In checkValue, Value: " << value << "\n";
	if (value < 0 || value > 1000)
		return (false);
	return (true);
}

/*
	Central - checkLine checks:
		- Format
		- Date
		- Value
*/
bool	BitcoinExchange::checkLine(const std::string &line, int *line_in_inputFile) const
{
	std::istringstream sstream(line);
	char dash1, dash2, pipe;
	int	year, month, day;
	long double	value;

	if (!(sstream >> year >> dash1 >> month >> dash2 >> day >> pipe >> value))
	{
		std::cout << coloring ("Line in Input File: " + std::to_string(*line_in_inputFile), PURPLE) << "\n";
		throw (std::runtime_error("Line " + std::to_string(*line_in_inputFile) + " - Bad Input (line not in the right format)\n" + line + "\n"));
	}
	if (!(sstream >> std::ws).eof())
		throw std::runtime_error("Unexpected characters in line");
	if (dash1 != '-' || dash2 != '-' || pipe != '|')
	{
		std::cout << coloring ("Line in Input File: " + std::to_string(*line_in_inputFile), PURPLE) << "\n";
		throw (std::runtime_error("Line " + std::to_string(*line_in_inputFile) + " - Bad Input ('-', '|')\n" + line + "\n"));
	}
	if (!checkDate(year, month, day))
	{
		std::cout << coloring ("Line in Input File: " + std::to_string(*line_in_inputFile), PURPLE) << "\n";
		throw (std::runtime_error("Line " + std::to_string(*line_in_inputFile) + " - Impossible Date\n" + line + "\n"));
	}
	if (!checkValue(value))
	{
		std::cout << coloring ("Line in Input File: " + std::to_string(*line_in_inputFile), PURPLE) << "\n";
		throw (std::runtime_error("Line " + std::to_string(*line_in_inputFile) + " - Wrong Value\n" + line + "\n"));
	}
	return (true);
}

bool	BitcoinExchange::preContentCheck(std::ifstream& file) const
{
	if (!checkFileFormat(this->_InputFile)) // Datei endet mit .txt
		throw (std::runtime_error("File must be a *.txt file"));
	if (!file.is_open())
		throw (std::runtime_error("Failed to open file " + this->_InputFile));
	if (!checkHeader(file))
		throw (std::runtime_error("Wrong File Header"));
	return (true);
}

/*
	Entry Point-Parser for the Input-File:
		Loop through input file, line by line and call appropriate functs to
		check variables
*/
bool	BitcoinExchange::checkInputFile(void) const
{
	int	line_in_inputFile;
	std::ifstream file(this->_InputFile);

	try
	{
		this->preContentCheck(file);
	}
	catch(const std::exception& e)
	{
		printer::LogException(e, __FILE__, __FUNCTION__, __LINE__);
		exit (1);
	}

	line_in_inputFile = 1;
	std::string line;
	while (std::getline(file, line))
	{
		if (line.empty() || std::all_of(line.begin(), line.end(), ::isspace))
		{
			++line_in_inputFile;
			continue ;
		}
		++line_in_inputFile;
		try
		{
			this->checkLine(line, &line_in_inputFile);
		}
		catch(const std::exception& e)
		{
			printer::LogException(e, __FILE__, __FUNCTION__, __LINE__);
		}
	}
	return (true);
}
// PARSER -- END


