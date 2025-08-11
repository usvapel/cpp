/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:30:32 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/11 13:30:41 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::_nbAccounts         = 0;
int Account::_totalAmount        = 0;
int Account::_totalNbDeposits    = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit)
{
	_displayTimestamp();

	std::cout << "index:" << _nbAccounts << ";amount:" << initial_deposit << ";created" << std::endl;

	_accountIndex = _nbAccounts;
	_totalAmount += initial_deposit;
	_nbAccounts++;
}

Account::~Account()
{
	_displayTimestamp();

	std::cout	<< "index:"   << _accountIndex
				<< ";amount:" << _amount
				<< ";closed"
				<< std::endl;
}

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();

	std::cout	<< "accounts:"     << _nbAccounts 
				<< ";total:"       << _totalAmount
				<< ";deposits:"	   << _totalNbDeposits
				<< ";withdrawals:" << _totalNbWithdrawals
				<< std::endl;
}

void Account::makeDeposit(int deposit)
{
	_amount      += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;

	_displayTimestamp();

	std::cout	<< "index:"        << _accountIndex
				<< ";p_amount:"    << _amount - deposit
				<< ";deposit:"     << deposit
				<< ";amount:"      << _amount
				<< ";nb_deposits:" << _nbDeposits
				<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();

	if (withdrawal > _amount)
	{
		std::cout	<< "index:"     << _accountIndex
					<< ";p_amount:" << _amount
					<< ";withdrawal:refused" 
					<< std::endl;
		return false;
	}

	_amount      -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;

	std::cout	<< "index:"           << _accountIndex
				<< ";p_amount:"       << _amount + withdrawal
				<< ";withdrawal:"     << withdrawal
				<< ";amount:"         << _amount
				<< ";nb_withdrawals:" << _nbWithdrawals
				<< std::endl;

	return true;
}

int	Account::checkAmount(void) const
{
	return _amount;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();

	std::cout	<< "index:"       << _accountIndex
				<< ";amount:"     << _amount
				<< ";deposits:"    << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals
				<< std::endl;
}

void Account::_displayTimestamp(void)
{
	std::time_t	rawtime;
	std::tm		*timeinfo;
	char		buffer[80];

	std::time(&rawtime);

	timeinfo = std::localtime(&rawtime);

	std::strftime(buffer, 80, "[%Y%m%d_%H%M%S] ", timeinfo);

	std::cout << buffer;
}
