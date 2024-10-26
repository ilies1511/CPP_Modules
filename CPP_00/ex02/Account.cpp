/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 00:06:49 by iziane            #+#    #+#             */
/*   Updated: 2024/10/26 17:31:51 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

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
	std::cout << std::put_time(&localTime, "[%Y%m%d_%H%M%S]") << std::endl;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount() \
		<< ";deposits:" << getNbDeposits() \
			<< ";withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account(int initial_doposit)
{
	_accountIndex = getNbAccounts();
	_amount = initial_doposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
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
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount \
		<< ";deposit:" << deposit << ";amount:" << _amount + deposit\
			<< ";nb_deposits:" << _nbDeposits << std::endl;
	_amount = _amount + deposit;
	return ;
}
