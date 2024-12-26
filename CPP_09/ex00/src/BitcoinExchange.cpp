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
	while (getline(database, line))
	{
		std::istringstream iss(line);
		std::string			date;
		std::string			rateStr;
		if (std::getline(iss, date, ',') && std::getline(iss, rateStr))
		{
			try
			{
				double rate = std::stod(rateStr);
				this->_dataBase[date] = rate; //OG-Syntax: this->_dataBase.insert({date, rate});
			}
			catch (const std::exception &e)
			{
				printer::LogException(e, __FILE__, __FUNCTION__, __LINE__);
				return ;
			}
		}
		else
		{
			std::string error_msg= "Content of " + this->_DataBaseFile + " wrong !";
			throw (std::runtime_error(error_msg));
		}
	}
	database.close();
}


