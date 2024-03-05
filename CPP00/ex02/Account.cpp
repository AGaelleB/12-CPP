#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

/******************* INIT DES ATTRIBUTS NON MEMBRES **********************/

	int	Account::_nbAccounts = 0;
	int	Account::_totalAmount = 0;
	int	Account::_totalNbDeposits = 0;
	int	Account::_totalNbWithdrawals = 0;


/***************************** CONST DEST *******************************/

Account::Account(int initial_deposit)  {

	// initialisation des variables membres
	this->_accountIndex = this->getNbAccounts();
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	// maj des attributs non membres
	Account::_totalAmount += initial_deposit;

	// affichage des constructions
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->checkAmount();
	std::cout << ";created";
	std::cout << std::endl;

	// maj du nbr de comptes
	Account::_nbAccounts++;

return;
}

Account::~Account(void) {

	// affichage des destructions
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->checkAmount();
	std::cout << ";closed";
	std::cout << std::endl;

	// maj du nbr de comptes
	Account::_nbAccounts--;
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

void	Account::displayAccountsInfos(void) {

	Account::_displayTimestamp();

	std::cout << " accounts:" << Account::getNbAccounts();
	std::cout << ";total:" << Account::getTotalAmount();
	std::cout << ";deposit:" << Account::getNbDeposits();
	std::cout << ";withdrawals:" << Account::getNbWithdrawals();
	std::cout << std::endl;

	return ;
}

/***************************** FUNCTIONS *******************************/

void	Account::makeDeposit(int deposit) {

	Account::_displayTimestamp();

	this->_nbDeposits++;
	Account::_totalNbDeposits++;

	std::cout << " index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << (this->_amount + deposit);
	std::cout << ";nb_deposits:" << this->_nbDeposits;
	std::cout << std::endl;

	// Maj de la somme après depot
	this->_amount += deposit;
	Account::_totalAmount += deposit;

	return ;
}

bool	Account::makeWithdrawal(int withdrawal) {

	Account::_displayTimestamp();

	std::cout << " index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";withdrawals:";
	if (withdrawal > this->checkAmount())
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	// Maj de la somme après le retrait
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;

	// Maj de nb de retrait que si pas refusé
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;

	std::cout << withdrawal;
	std::cout << ";amount:" << (this->_amount - withdrawal);
	std::cout << ";nb_Withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;

	return (true);
}


int	Account::checkAmount(void) const {

	return (this->_amount);
}

void	Account::displayStatus(void) const {

	Account::_displayTimestamp();

	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->checkAmount();
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;

	return ;
}

void	Account::_displayTimestamp(void) {

	time_t now = time(NULL);

	// Convertir en format local
	std::tm *ltm = std::localtime(&now);

	// Buffer pour stocker la date et l'heure
	char buffer[80];
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", ltm);

	std::cout << buffer;

	return ;
}