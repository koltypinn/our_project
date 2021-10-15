/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flyte <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:14:54 by flyte             #+#    #+#             */
/*   Updated: 2021/09/27 17:14:56 by flyte            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include <iomanip>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
	
void time_stamp() 
{
    time_t time;
    
    std::time(&time);
    struct tm *local_time = localtime(&time);
    std::cout << "[" << local_time->tm_year + 1900;
    std::cout <<  std::setfill ('0') << std::setw (2) << local_time->tm_mon + 1;
    std::cout <<  std::setfill ('0') << std::setw (2) << local_time->tm_mday << "_";
    std::cout <<  std::setfill ('0') << std::setw (2) << local_time->tm_hour;
    std::cout <<  std::setfill ('0') << std::setw (2) << local_time->tm_min;
    std::cout <<  std::setfill ('0') << std::setw (2) << local_time->tm_sec << "] ";
}

Account::Account( int initial_deposit )
{
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_accountIndex = _nbAccounts;
    Account::_nbAccounts++;
    this->_amount = initial_deposit;
    Account::_totalAmount += _amount;
    time_stamp();
    std::cout << "index:" << this->_accountIndex << ";amount:";
    std::cout << this->_amount << ";created";
    std::cout << std::endl;
    return ;
}

Account::~Account( void )
{
    Account::_nbAccounts--;
    Account::_totalAmount -= _amount;
    Account::_totalNbDeposits -= _nbDeposits;
    time_stamp();
    std::cout << "index:" << this->_accountIndex << ";amount:";
    std::cout << this->_amount << ";closed";
    std::cout << std::endl;
    return ;
}

int	Account::getNbAccounts( void )
{
    return Account::_nbAccounts;
}

int	Account::getTotalAmount( void )
{
    return Account::_totalAmount;
}

int	Account::getNbDeposits( void )
{
    return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
    return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
    time_stamp();
    std::cout << "accounts:" << getNbAccounts() << ";total:";
    std::cout << getTotalAmount() << ";deposites:";
    std::cout << getNbDeposits();
    std::cout << ";withdrawals:" << getNbWithdrawals();
    std::cout << std::endl;
}

void	Account::displayStatus( void ) const
{
    time_stamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount;
    std::cout << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals;
    std::cout << std::endl;
}
void	Account::makeDeposit( int deposit )
{
    time_stamp();
    std::cout << "index:" << _accountIndex << ";p_amount:";
    std::cout << _amount << ";deposit:" << deposit;
    _amount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;
    std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits;
    std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    time_stamp();
    std::cout << "index:" << _accountIndex << ";p_amount:";
    std::cout << _amount;
    if (withdrawal > _amount) {
        std::cout << ";withdrowal:refused";
        std::cout << std::endl;
        return (false);
    } else {
        _amount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        _totalAmount -= withdrawal;
        std::cout << ";withdrowal:" << withdrawal << ";amount:";
        std::cout << _amount << ";nb_withdrawals:" << _nbWithdrawals;
    }
    std::cout << std::endl;
    return (false);
}

int		Account::checkAmount( void ) const 
{
     return (_amount);
}

