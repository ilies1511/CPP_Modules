#include "RPN.hpp"
#include "printer.hpp"
#include "Log.hpp"

const std::array<char, 4> ReversePolishNotation::_OperationTokens = {'+', '-', '/', '*'};

//OCF -- BEGIN
ReversePolishNotation::ReversePolishNotation(void)
	: _data(), _rawStr("DefaultSTR")
{
	printer::ocf_printer("ReversePolishNotation", printer::OCF_TYPE::DC);
}

ReversePolishNotation::ReversePolishNotation(const std::string &input_str)
	: _data(), _rawStr(input_str)
{
	printer::ocf_printer("ReversePolishNotation", printer::OCF_TYPE::DNC);
}

ReversePolishNotation::ReversePolishNotation(const ReversePolishNotation &og)
	: _data(og._data), _rawStr(og._rawStr)
{
	printer::ocf_printer("ReversePolishNotation", printer::OCF_TYPE::CC);
}

ReversePolishNotation &ReversePolishNotation::operator=(const ReversePolishNotation &og)
{
	if (this != &og)
	{
		printer::ocf_printer("ReversePolishNotation", printer::OCF_TYPE::CAC);
		this->_data = og._data;
		this->_rawStr = og._rawStr;
	}
	return (*this);
}

ReversePolishNotation::~ReversePolishNotation(void)
{
	printer::ocf_printer("ReversePolishNotation", printer::OCF_TYPE::D);
}
//OCF -- END
