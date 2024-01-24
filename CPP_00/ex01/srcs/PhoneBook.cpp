#include <iostream>
#include <string>
#include "../includes/PhoneBook.hpp"
#include "../includes/Contact.hpp"

PhoneBook::PhoneBook(void) {
	// std::cout << "Constructor PhoneBook called" << std::endl;
	return;
}

PhoneBook::~PhoneBook(void) {
	// std::cout << "*Destructor PhoneBook called*" << std::endl;
	return;
}

void	PhoneBook::OpenPhoneBook(void) const {
	std::cout << std::endl;
	std::cout << "* * * * * * * Your  PhoneBook * * * * * * * * *" << std::endl;
	std::cout << "*                                             *" << std::endl;
	std::cout << "*  To add contact please write \"ADD\"          *" << std::endl;
	std::cout << "*  To search contact please write \"SEARCH\"    *" << std::endl;
	std::cout << "*  To exit contact please write \"EXIT\"        *" << std::endl;
	std::cout << "*                                             *" << std::endl;
	std::cout << "* * * * * * * * * * * * * * * * * * * * * * * *" << std::endl;
	std::cout << std::endl;
	return;
}

void PhoneBook::AddContact(void) {
	return;
}


void PhoneBook::SearchContact(void) {
	std::cout << "* * * * * * * Your Contacts * * * * * * * * *" << std::endl;

	return;
}

void PhoneBook::PrintContact(void) {

	std::cout << std::endl;
	std::cout << "* * * * * * * Your Contacts * * * * * * * * *" << std::endl;

	return;
}

void PhoneBook::ExitContact(void) {
	return;
}