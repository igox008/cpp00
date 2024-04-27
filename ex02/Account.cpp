/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:50:22 by alaassir          #+#    #+#             */
/*   Updated: 2024/04/27 16:28:38 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	Account::_displayTimestamp();
	std::cout << "New account get created" << std::endl;
	this->_amount = initial_deposit;
	this->_accountIndex = this->getNbAccounts();
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += initial_deposit;
	Account::_nbAccounts++;
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << "Account with Index " << this->_accountIndex << " closed" << std::endl;
	Account::_nbAccounts--;
}

int	Account::getNbAccounts(void) {return (Account::_nbAccounts);}

int	Account::getNbDeposits(void) {return (Account::_totalNbDeposits);}

int	Account::getTotalAmount(void) {return (Account::_totalAmount);}

int Account::getNbWithdrawals(void) {return (Account::_totalNbWithdrawals);}

void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "Account with index " << this->_accountIndex << " make a deposit with an amount " << deposit << std::endl;
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (this->_amount < withdrawal)
	{
		std::cout << "You can't withdraw " << withdrawal << " because you only have " << this->_amount << std::endl;
		return (false);
	}
	Account::_displayTimestamp();
	std::cout << "Account with index " << this->_accountIndex << " make a withdrawal with an amount " << withdrawal << std::endl;
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	return (true);
}

void	Account::_displayTimestamp(void)
{
	time_t now = time(0);
	struct tm *currentTime = localtime(&now);

	int year = currentTime->tm_year + 1900;
	int month = currentTime->tm_mon + 1;
	int day = currentTime->tm_mday;
	int hour = currentTime->tm_hour;
	int minute = currentTime->tm_min;
	int second = currentTime->tm_sec;

	std::cout << "Current Date: "
			  << std::setw(4) << std::setfill('0') << year << '-'
			  << std::setw(2) << std::setfill('0') << month << '-'
			  << std::setw(2) << std::setfill('0') << day << " | ";
	std::cout << "Current Time: "
			  << std::setw(2) << std::setfill('0') << hour << ':'
			  << std::setw(2) << std::setfill('0') << minute << ':'
			  << std::setw(2) << std::setfill('0') << second << std::endl;	
}

void	Account::displayStatus(void) const
{
	std::cout << "---------- Account nbr " << this->_accountIndex << " Infos ----------" << std::endl;
	std::cout << "--> Account balance   : " << this->_amount << std::endl;
	std::cout << "--> Deposits count    : " << this->_nbDeposits << std::endl;
	std::cout << "--> Withdrawals count : " << this->_nbWithdrawals << std::endl;
	Account::_displayTimestamp();
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "---------- General information ----------" << std::endl;
	std::cout << "--> Accounts Number   : " << Account::getNbAccounts() << std::endl;
	std::cout << "--> Total amount      : " << Account::getTotalAmount() << std::endl;
	std::cout << "--> Total Deposits    : " << Account::getNbDeposits() << std::endl;
	std::cout << "--> Total Withdrawals : " << Account::getNbWithdrawals() << std::endl;
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}