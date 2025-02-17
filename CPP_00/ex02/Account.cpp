#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
	std::time_t now = std::time(nullptr);
    std::tm *tm_now = std::localtime(&now);
    std::cout << std::put_time(tm_now, "[%Y%m%d_%H%M%S] ");
}

Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _amount = initial_deposit;
    _totalAmount += _amount;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex <<";amount:"<<_amount<<";created"<<std::endl;
}
Account::~Account()
{
    _displayTimestamp();
     std::cout << "index:" << _accountIndex <<";amount:"<<_amount<<";close"<<std::endl;
}
void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout<<"accounts:"<<_nbAccounts <<";total:"<<_totalAmount
    <<";deposits:"<<_totalNbDeposits<<";withdrawals:"<<_totalNbWithdrawals<<std::endl;
}
void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex <<";amount:"<<_amount
    <<";deposits:"<<_nbDeposits<<";withdrawals:"<<_nbWithdrawals<<std::endl;
}

void	Account::makeDeposit( int deposit )
{
    int p_amount;

    _displayTimestamp();
    p_amount = _amount;
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    std::cout<<"index:"<<_accountIndex<<";p_amount:"<<p_amount
    <<";deposit:"<<deposit<<";amount:"<<_amount<< ";nb_deposits:"<<_nbDeposits<<std::endl;
}
bool	Account::makeWithdrawal( int withdrawal )
{
    int p_amount;

    _displayTimestamp();
    if(withdrawal > _amount)
    {
         std::cout << "index:" << _accountIndex <<";p_amount:"<<_amount<<";withdrawal:refused"<<std::endl;
         return (false);
    }
    p_amount = _amount;
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout<<"index:"<<_accountIndex<<";p_amount:"<<p_amount
    <<";withdrawal:"<<withdrawal<<";amount:"<<_amount<< ";nb_withdrawals:"<<_nbWithdrawals<<std::endl;
    return (true);
}

int		Account::checkAmount( void ) const
{
    return (_amount);
}
int		Account::getNbAccounts( void )
{
    return (_nbAccounts);
}
int		Account::getTotalAmount( void )
{
    return (_totalAmount);
}
int		Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}
int		Account::getNbWithdrawals( void )
{
    return(_totalNbWithdrawals);
}