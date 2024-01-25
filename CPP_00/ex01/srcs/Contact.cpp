#include <iostream>
#include <string>
#include "../includes/PhoneBook.hpp"
#include "../includes/Contact.hpp"

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string BLUE = "\033[34m";
const std::string YELLOW = "\033[33m";

/***************************** CONST DEST *****************************/


Contact::Contact(void) : _index(0) {
	return;
}

Contact::~Contact(void) {
	return;
}

/******************************* GETTER *******************************/

std::string Contact::getFirstName(void) const {
	return (this->_firstName);
}

std::string Contact::getLastName(void) const {
	return
	 (this->_lastName);
}
std::string Contact::getNickname(void) const {
	return (this->_nickname);
}

std::string Contact::getPhoneNumber(void) const {
	return (this->_phoneNumber);
}

std::string Contact::getDarkestSecret(void) const {
	return (this->_darkestSecret);
}

int Contact::getIndex(void) const {
	return (this->_index);
}

/******************************* SETTER *******************************/

void Contact::setFirstName(std::string userInput) {
	if (!userInput.empty())
		this->_firstName = userInput;
	else
		std::cout << RED << "First name cannot be empty." << RESET << std::endl;
}

void Contact::setLastName(std::string userInput) {
	if (!userInput.empty())
		this->_lastName = userInput;
	else
		std::cout << RED << "Last name can't be empty." << RESET << std::endl;
}

void Contact::setNickname(std::string userInput) {
	if (!userInput.empty())
		this->_nickname = userInput;
	else
		std::cout << RED << "Nickname name can't be empty." << RESET << std::endl;
}

void Contact::setPhoneNumber(std::string userInput) { // protection pour chiffre etc
	if (!userInput.empty())
		this->_phoneNumber = userInput;
	else
		std::cout << RED << "Phone number can't be empty." << RESET << std::endl;
}

void Contact::setDarkestSecret(std::string userInput) {
	if (!userInput.empty())
		this->_darkestSecret = userInput;
	else
		std::cout << RED << "Darkest secret can't be empty." << RESET << std::endl;
}


void Contact::setIndex(int userInput) {
	if (userInput >= 0)
		this->_index = userInput;
	else
		std::cout << RED << "Invalid input." << RESET << std::endl;

}