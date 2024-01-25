#include <iostream>
#include <string>
#include "../includes/PhoneBook.hpp"
#include "../includes/Contact.hpp"

Contact::Contact(void) {
	// std::cout << "Constructor Contact called" << std::endl;
	return;
}

Contact::~Contact(void) {
	// std::cout << "*Destructor Contact called*" << std::endl;
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
	this->_firstName = userInput;
}

void Contact::setLastName(std::string userInput) {
	this->_lastName = userInput;
}

void Contact::setNickname(std::string userInput) {
	this->_nickname = userInput;
}

void Contact::setPhoneNumber(std::string userInput) {
	this->_phoneNumber = userInput;
}

void Contact::setDarkestSecret(std::string userInput) {
	this->_darkestSecret = userInput;
}

void Contact::setIndex(int userInput) {
	this->_index = userInput;
}