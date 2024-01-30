#include <iostream>
#include "Account.hpp"

/******************* INIT DES ATTRIBUTS NON MEMBRES **********************/

	int	Account::_nbAccounts = 0;
	int	Account::_totalAmount = 0;
	int	Account::_totalNbDeposits = 0;
	int	Account::_totalNbWithdrawals = 0;


/***************************** CONST DEST *******************************/

Account::Account(void) {
	return;
}

Account::~Account(void) {
	return;
}


/******************************* GETTERS *******************************/
/********************** ET FONCTION NON MEMBRES ************************/

int	Account::getNbAccounts(void) {
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void) {
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void) {
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void) {
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void) { // fonction non membre
	return ;
}

/***************************** FUNCTIONS *******************************/

// public //

void	Account::makeDeposit(int deposit) {

}

bool	Account::makeWithdrawal(int withdrawal) {

	return (true);
}

int	Account::checkAmount(void) const {
	return (this->_amount);
}

void	Account::displayStatus(void) const {

}


// private //

void	Account::_displayTimestamp(void) {  // fonction non membre privee

}