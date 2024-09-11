/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarggra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:28:47 by fmarggra          #+#    #+#             */
/*   Updated: 2024/06/19 16:54:27 by fmarggra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

//private static variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//public static
int	Account::getNbAccounts(void) {
    return _nbAccounts;
}

int	Account::getTotalAmount(void) {
    return _totalAmount;
}

int	Account::getNbDeposits(void) {
    return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void) {
    return _totalNbWithdrawals;
}
	
void	Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout   << "accounts:"     << getNbAccounts()
                << ";total:"        << getTotalAmount()
                << ";deposits:"     << getNbDeposits()
                << ";withdrawals:"  << getNbWithdrawals()
                << std::endl;
}

//private static
void    Account::_displayTimestamp() {
    std::time_t time;
    std::time(&time);
    std::tm* actualTime = std::localtime(&time);
    std::cout   << "["
                << (actualTime->tm_year + 1900)
                << (actualTime->tm_mon + 1 < 10 ? "0" : "")
                << (actualTime->tm_mon + 1)
                << (actualTime->tm_mday < 10 ? "0" : "")
                << actualTime->tm_mday << "_"
                << (actualTime->tm_hour < 10 ? "0" : "")
                << actualTime->tm_hour
                << (actualTime->tm_min < 10 ? "0" : "")
                << actualTime->tm_min
                << (actualTime->tm_sec < 10 ? "0" : "")
                << actualTime->tm_sec
                << "] "; 
}

//constructor
Account::Account(int initial_deposit)
        :   _accountIndex(_nbAccounts++),
            _amount(initial_deposit),
            _nbDeposits(0),
            _nbWithdrawals(0) {
                _totalAmount += initial_deposit;
                _displayTimestamp();
                std::cout   << "index:"     << _accountIndex
                            << ";amount:"   << _amount
                            << ";created"   << std::endl;
            }

Account::~Account() {
    _displayTimestamp();
    std::cout   << "index:"    << _accountIndex
                << ";amount:"   << _amount
                << ";closed"    <<  std::endl;
}

//public member functions
void    Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout   << "index:"         << _accountIndex
                << ";p_amount:"     << _amount
                << ";deposit:"      << deposit
                << ";amount:"       << (_amount + deposit)
                << ";nb_deposits:"   << (_nbDeposits + 1)
                << std::endl;

    _amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits++;
    _nbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout   << "index:"     << _accountIndex
                << ";p_amount:" << _amount;
    if (_amount < withdrawal) {
        std::cout << ";withdrawal:refused" << std::endl;
        return 0;
    }
    std::cout   << ":withdrawal:"       << withdrawal
                << ";amount:"           << (_amount - withdrawal)
                << ";nb_withdrawals:"   << (_nbWithdrawals + 1)
                << std::endl;

    _nbWithdrawals++;
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    return 1;
}

int		Account::checkAmount( void ) const {
    return _amount;
}

void	Account::displayStatus( void ) const {
    _displayTimestamp();
    std::cout   << "index:"         << _accountIndex
                << ";amount:"       << _amount
                << ";deposits:"      << _nbDeposits
                << ";withdrawals:"  << _nbWithdrawals
                << std::endl;
}
