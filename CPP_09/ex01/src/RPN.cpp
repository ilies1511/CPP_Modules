/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:11:10 by iziane            #+#    #+#             */
/*   Updated: 2025/01/15 23:11:11 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "printer.hpp"
#include "Log.hpp"

// const std::array<char, 4> ReversePolishNotation::_OperationTokens = {'+', '-', '/', '*'};
const std::unordered_set<char> ReversePolishNotation::_OperationTokens = {'+', '-', '/', '*'};

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

//Helper -- BEGIN
void	ReversePolishNotation::printStack(void) const
{
	std::stack<int> tempStack(this->_data);

	// !tempStack.empty()
	while (!tempStack.empty())
	{
		std::cout << tempStack.top() << " ";
		tempStack.pop(); // Entferne das oberste Element
	}
	std::cout << std::endl;
}

void ReversePolishNotation::pushDigit(int x)
{
	this->_data.push(x);
}

void ReversePolishNotation::setString(const std::string& str)
{
	while (!(this->_data.empty()))
		this->_data.pop();
	this->_rawStr = str;
}

const int &ReversePolishNotation::getTop(void) const
{
	return (this->_data.top());
}

//Helper -- END

//RPN-FUNCS -- BEGIN
void	ReversePolishNotation::doOperation(char OperationToken)
{
	int	res = 0;

	int	a = _data.top();
	_data.pop();
	int	b = _data.top();
	_data.pop();

	switch (OperationToken)
	{
		case '+': res = b + a; break;
		case '-': res = b - a; break;
		case '*': res = b * a; break;
		case '/':
			if (a == 0)
				throw (std::runtime_error("Error: can not divide by 0 !"));
			res = b / a;
			break;
		default:
			throw(std::invalid_argument("Error: invalid operation !"));
	}
	// std::cout << b << OperationToken << a << " = " << res << "\n";
	this->_data.push(res);
}

void	ReversePolishNotation::processInput(void)
{
	std::string token;
	std::stringstream ss(this->_rawStr);

	try
	{
		while (ss >> token)
		{
			/*
				Digit-Check:
					Wenn aktueller String Zahl ist, dann Range-Check
			*/
			if (std::all_of(token.begin(), token.end(), ::isdigit))
			{
				int digit = std::stoi(token);
				if (digit < 0 || digit >= 10)
					throw (std::out_of_range("Error: token " + token + " out of range (0-9) !"));
				this->_data.push(digit);
			}
			/*
				Operation-Token Check:
					this->_OperationTokens.count(token[0]) --> checks wether
					token in appropriate size + if token is in _OperationTokens
			*/
			else if (token.size() == 1 && this->_OperationTokens.count(token[0]))
			{
				if (this->_data.size() < 2)
					throw (std::runtime_error("Error: not enough operands for operation !"));
				this->doOperation(token[0]);
			}
			else
				throw (std::invalid_argument("Error: Invalid token " + token));
			// std::cout << "\"" << token << "\"" <<"\n";
		}
		//Am Ende muss nur noch ein Element im Stack sein
		if (_data.size() != 1)
			throw std::runtime_error("Error: Invalid RPN-Expression (n = Amount of Digits : k = n - 1 = Amount of Operation-Tokens)");
		// std::cout << coloring("Result: " + std::to_string(_data.top()) + "\n", GREEN);
	}
	catch(const std::exception& e)
	{
		throw ;
	}
}
//RPN-FUNCS -- END
