#include "../includes/PhoneBook.hpp"

/***************************** CONST DEST *******************************/

Contact::Contact(void) : _index(1) {
	return;
}

Contact::~Contact(void) {
	return;
}

/******************************* GETTERS *******************************/

std::string Contact::getFirstName(void) const {
	return (this->_firstName);
}

std::string Contact::getLastName(void) const {
	return (this->_lastName);
}

std::string Contact::getNickname(void) const {
	return (this->_nickname);
}

unsigned long int Contact::getPhoneNumber(void) const {
	return (this->_phoneNumber);
}

std::string Contact::getDarkestSecret(void) const {
	return (this->_darkestSecret);
}

int Contact::getIndex(void) const {
	return (this->_index);
}

/******************************* SETTERS *******************************/

void Contact::setFirstName(std::string userInput) {
	if (!userInput.empty())
		this->_firstName = userInput;
	else
		std::cout << "First name cannot be empty." << std::endl;
}

void Contact::setLastName(std::string userInput) {
	if (!userInput.empty())
		this->_lastName = userInput;
	else
		std::cout << "Last name can't be empty." << std::endl;
}

void Contact::setNickname(std::string userInput) {
	if (!userInput.empty())
		this->_nickname = userInput;
	else
		std::cout << "Nickname name can't be empty." << std::endl;
}

void Contact::setPhoneNumber(unsigned long int userInput) {
	this->_phoneNumber = userInput;
}

void Contact::setDarkestSecret(std::string userInput) {
	if (!userInput.empty())
		this->_darkestSecret = userInput;
	else
		std::cout << "Darkest secret can't be empty." << std::endl;
}


void Contact::setIndex(int userInput) {
	if (userInput >= 0)
		this->_index = userInput;
	else
		std::cout << "Invalid input." << std::endl;

}