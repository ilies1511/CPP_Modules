/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 00:06:49 by iziane            #+#    #+#             */
/*   Updated: 2024/10/26 23:03:03 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

/*
	Comparing *.log file outputs:
		1. make re && ./account > final
		2. awk '{$1=""}1' final > final_cut
		3. awk '{$1=""}1' 19920104_091532.log > og_cut
		3. diff og_cut final_cut
*/

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp(void)
{
	std::time_t now = std::time(nullptr);
	std::tm localTime;

	localtime_r(&now, &localTime);
	std::cout << std::put_time(&localTime, "[%Y%m%d_%H%M%S]");
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount \
		<< ";deposits:" << _totalNbDeposits \
			<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account(int initial_doposit)
{
	_accountIndex = getNbAccounts();
	_amount = initial_doposit;
	_totalAmount = _totalAmount + _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount \
		<< ";created" << std::endl;
}

Account::Account()
{
	_accountIndex = getNbAccounts();
	_amount = 0;
	_totalAmount = _totalAmount + _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount \
		<< ";created" << std::endl;
	return ;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount \
		<< ";closed" << std::endl;
	return ;
}

void	Account::makeDeposit(int deposit)
{
	_totalAmount = _totalAmount + deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount \
		<< ";deposit:" << deposit << ";amount:" << _amount + deposit\
			<< ";nb_deposits:" << _nbDeposits << std::endl;
	_amount = _amount + deposit;
	return ;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (_amount == 0 || _amount < withdrawal)
	{
		_displayTimestamp();
		std::cout << " index:" << _accountIndex << ";p_amount:" << _amount \
			<< ";withdrawal:refused" << std::endl;
		return (false);
	}
	_totalAmount = _totalAmount - withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount \
		<< ";withdrawal:" << withdrawal << ";amount:" << _amount - withdrawal \
			<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	_amount = _amount - withdrawal;
	return (true);
}

int	Account::checkAmount(void) const
{
	//TODO: Check if _totalAmount or with getter (getTotalAmount( void );)
	return (_totalAmount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount \
		<< ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals \
			<< std::endl;
	return ;
}

// //Old Versoon
// void	Account::displayStatus( void ) const
// {
// 	_displayTimestamp();
// 	std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount\
// 		<< ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals\
// 			<< std::endl;
// 	return ;
// }
