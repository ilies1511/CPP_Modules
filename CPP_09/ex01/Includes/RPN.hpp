/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:10:25 by iziane            #+#    #+#             */
/*   Updated: 2025/01/15 23:10:25 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
#include <array>
#include <deque>
#include <stack>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <regex>
#include <unordered_set>

//Own
#include "printer.hpp"

//Class
class ReversePolishNotation
{
	private:
		std::stack<int> _data;
		std::string _rawStr;
		// static const std::array<char, 4> _OperationTokens;
		static const std::unordered_set<char> _OperationTokens;
	//OCF
	public:
		ReversePolishNotation(void); //Run own tests
		ReversePolishNotation(const std::string &input_str);
		ReversePolishNotation(const ReversePolishNotation &og);
		ReversePolishNotation &operator=(const ReversePolishNotation &og);
		~ReversePolishNotation(void);
	//Methodes
	private:
		void	doOperation(char OperationToken);
	//Methodes
	public:
		/*
			In while-Loop using sstream:
				1. checks, wether current element is digit && in Range of (0 -10);
				2. If '1.' went errorfree, push element to stack.
				3. If '1.' recognized Operation Token, to operation, and push back to stack
		*/
		void	processInput(void);
	//Test
	public:
		void printStack(void) const;
		void pushDigit(int x);
		void setString(const std::string& str);
		const int &getTop(void) const;
		// const std::string getRaInputStr(void) const;
		//Getter, die mir zwei Elemente des Stacks rausgibt in Form von Pair
};

