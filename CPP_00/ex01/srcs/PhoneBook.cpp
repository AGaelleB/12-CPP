#include <iostream>
#include <string>
#include "../includes/PhoneBook.hpp"
#include "../includes/Contact.hpp"

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string BLUE = "\033[34m";
const std::string YELLOW = "\033[33m";


PhoneBook::PhoneBook(void) : _contactCount(1) {
	return;
}

PhoneBook::~PhoneBook(void) {
	return;
}

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

void PhoneBook::AddContact(void) {
	
	if (_contactCount <= 8) {

		Contact newContact;
		std::string userInput;
		std::cout << BLUE << "* * * * * * * * * * * * * * * * * * * * * * * *" << RESET << std::endl;
		DataContact(newContact);
		newContact.setIndex(_contactCount);
		_Contacts[_contactCount] = newContact;
		_contactCount++;
		// std::cout << "Contact added with index: " << newContact.getIndex() << std::endl;
		std::cout << BLUE << "* * * * * * * * * * * * * * * * * * * * * * * *" << RESET << std::endl;
	} else {
		Contact newContact;
		std::string userInput;
		DataContact(newContact);
		newContact.setIndex(_contactCount % 8 + 1);
		_Contacts[_contactCount % 8] = newContact;
		_contactCount++;
		if (_contactCount > 8)
			_contactCount = 1; // Réinitialisez à 1 une fois remplacé le 1er contact
	}
}

/* void PhoneBook::DataContact(Contact &newContact) {
	std::string userInput;
	std::string prompts[] = {
		"Enter your first name : ",
		"Enter your last name : ",
		"Enter your nickname : ",
		"Enter your phone number : ",
		"Enter your darkest secret : "
	};
	void (Contact::*setters[])(std::string) = {
		&Contact::setFirstName,
		&Contact::setLastName,
		&Contact::setNickname,
		&Contact::setPhoneNumber,
		&Contact::setDarkestSecret
	};

	for (int i = 0; i < 5; i++) {
		while (true) {
			std::cout << prompts[i];
			std::getline(std::cin, userInput);
			if (!userInput.empty()) {
				(newContact.*setters[i])(userInput);
				break;
			}
			else {
				std::cout << prompts[i] << " cannot be empty." << std::endl;
			}
		}
	}
}
 */

void PhoneBook::DataContact(Contact &newContact) {
	
	std::string userInput;

	while (1) {
		std::cout << "Enter your first name : ";
		std::getline(std::cin, userInput);
		if (!userInput.empty()) {
			newContact.setFirstName(userInput);
			break;
		}
		else {
			std::cout << "First name cannot be empty." << std::endl;
		}
	}
	while (1) {
		std::cout << "Enter your last name : ";
		std::getline(std::cin, userInput);
		if (!userInput.empty()) {
			newContact.setLastName(userInput);
			break;
		}
		else {
			std::cout << "Last name cannot be empty." << std::endl;
		}
	}
	while (1) {
		std::cout << "Enter your nickname : ";
		std::getline(std::cin, userInput);
		if (!userInput.empty()) {
			newContact.setNickname(userInput);
			break;
		}
		else {
			std::cout << "Nickname cannot be empty." << std::endl;
		}
	}
	while (1) {
		std::cout << "Enter your phone number : ";
		std::getline(std::cin, userInput);
		if (!userInput.empty()) {
			newContact.setPhoneNumber(userInput);
			break;
		}
		else {
			std::cout << "Phone number cannot be empty." << std::endl;
		}
	}
	while (1) {
		std::cout << "Enter your darkest secret : ";
		std::getline(std::cin, userInput);
		if (!userInput.empty()) {
			newContact.setDarkestSecret(userInput);
			break;
		}
		else {
			std::cout << "Darkest secret cannot be empty." << std::endl;
		}
	}
}


void PhoneBook::SearchContact(void) {
	int userInput;
	Contact indexContact;

	std::cout << std::endl;
	std::cout << BLUE << "* * * * * * * Your Contacts * * * * * * * * *" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << " -------------------------------------------" << std::endl;
	std::cout << "|  index   | 1st name | lastname | nickname |" << std::endl;
	std::cout << " -------------------------------------------" << std::endl;

	std::cout << std::endl;
	std::cout << "Please enter the contact index : ";
	std::cin >> userInput;
	indexContact.setIndex(userInput);
	// int contactIndex = indexContact.getIndex();
	std::cout << std::endl;

	return;
}

void PhoneBook::DisplayContact(void) {

	// if (_index > 0 && _index <= 8)
	// 	_Contacts[_index].DisplayContact();
	// else
		std::cout << "Invalid contact index." << std::endl;
	return;
}

void PhoneBook::ExitContact(void) {
	return;
}