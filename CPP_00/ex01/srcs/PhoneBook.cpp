#include <iostream>
#include <string>
#include <iomanip>
 #include <limits>
#include "../includes/PhoneBook.hpp"
#include "../includes/Contact.hpp"

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string BLUE = "\033[34m";
const std::string YELLOW = "\033[33m";


/***************************** CONST DEST *******************************/

PhoneBook::PhoneBook(void) : _contactCount(0) {
	return;
}

PhoneBook::~PhoneBook(void) {
	return;
}

/***************************** FUNCTIONS ********************************/

void PhoneBook::OpenPhoneBook(void) const {
	std::cout << std::endl;
	std::cout << BLUE << "* * * * * * * * Your  PhoneBook * * * * * * * *" << RESET << std::endl;
	std::cout << BLUE << "*                                             *" << RESET << std::endl;
	std::cout << BLUE << "*" << GREEN << "  To add contact write \"""ADD""\"" << BLUE << "                 *" << RESET << std::endl;
	std::cout << BLUE << "*" << YELLOW << "  To search for a contact write \"""SEARCH""\"" << BLUE << "     *" << RESET << std::endl;
	std::cout << BLUE << "*" << RED << "  To exit write \"""EXIT""\"" << BLUE << "                       *" << RESET << std::endl;
	std::cout << BLUE << "*                                             *" << RESET << std::endl;
	std::cout << BLUE << "* * * * * * * * * * * * * * * * * * * * * * * *" << RESET << std::endl;
	std::cout << std::endl;
	return;
}

// void PhoneBook::AddContact(void) {
// 	Contact newContact;
// 	DataContact(newContact);

// 	// Calculez l'indice où insérer le nouveau contact
// 	int index = _contactCount % 3;

// 	// Ajoutez le nouveau contact à l'index actuel
// 	newContact.setIndex(index);
// 	_PhoneBook[index] = newContact;

// 	// Incrémente le compteur de contacts
// 	_contactCount++;
// 	index++;

// 	// Si le tableau est plein, revenez au début
// 	if (_contactCount == 3) {
// 		index = 0;
// 	}
// }

void PhoneBook::AddContact(void) {
    Contact newContact;
    DataContact(newContact);

    int index = _contactCount % 3;
    newContact.setIndex(index);
    _PhoneBook[index] = newContact;

    if (_contactCount < 3) {
        _contactCount++;
    }
}



void PhoneBook::DataContact(Contact &newContact) {
	
	std::string userInput;
	while (1) {
		std::cout << std::endl;
		std::cout << "First name : ";
		std::getline(std::cin, userInput);
		if (!userInput.empty()) {
			newContact.setFirstName(userInput);
			break;
		}
	}
	while (1) {
		std::cout << "Last name : ";
		std::getline(std::cin, userInput);
		if (!userInput.empty()) {
			newContact.setLastName(userInput);
			break;
		}
	}
	while (1) {
		std::cout << "Nickname : ";
		std::getline(std::cin, userInput);
		if (!userInput.empty()) {
			newContact.setNickname(userInput);
			break;
		}
	}
	while (1) {
		std::cout << "Phone number : ";
		std::getline(std::cin, userInput);
		if (!userInput.empty()) {
			newContact.setPhoneNumber(userInput);
			break;
		}
	}
	while (1) {
		std::cout << "Your darkest secret : ";
		std::getline(std::cin, userInput);
		if (!userInput.empty()) {
			newContact.setDarkestSecret(userInput);
			std::cout << std::endl;
			break;
		}
	}
}

void PhoneBook::SearchContact(void) {

	std::cout << std::endl;
	std::cout << BLUE << "* * * * * * * * Your Contacts * * * * * * * * *" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << " -------------------------------------------" << std::endl;
	std::cout << "|  index   | 1st name | lastname | nickname |" << std::endl;
	std::cout << " -------------------------------------------" << std::endl;
	DisplayAllContacts();
	return;
}

void PhoneBook::DisplayAllContacts(void) {
	int	userInput;
	
	for (int i = 0; i < _contactCount; i++) {
		Contact &currentContact = _PhoneBook[i];
		std::cout << "|" << std::setw(10) << std::right << currentContact.getIndex() << "|";
		std::cout << "" << std::setw(10) << std::right << currentContact.getFirstName() << "|";
		std::cout << "" << std::setw(10) << std::right << currentContact.getLastName() << "|";
		std::cout << "" << std::setw(10) << std::right << currentContact.getNickname() << "|" << std::endl;
	}
	std::cout << std::endl;
	while (_contactCount > 0) {
		std::cout << "Please enter the contact index : ";
		std::cin >> userInput;
		if (userInput >= 0 && userInput < _contactCount) {
			DisplayContactIndex(userInput);
			break;
		}
		else {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		}
	}
}

void PhoneBook::DisplayContactIndex(int userInput) {
	Contact selectedContact = _PhoneBook[userInput];
	std::cout << std::endl;
	std::cout << GREEN << "* * * * * * * * * Contact n." << userInput << " * * * * * * * * *" << RESET << std::endl;
	std::cout << "Firstname: " << selectedContact.getFirstName() << std::endl;
	std::cout << "Lastname: " << selectedContact.getLastName() << std::endl;
	std::cout << "Nickname: " << selectedContact.getNickname() << std::endl;
	std::cout << "Phone number: " << selectedContact.getPhoneNumber() << std::endl;
	std::cout << std::endl;
}

void PhoneBook::ExitContact(void) {
	std::cout << "You chose to exit, bye." << std::endl;
	return;
}