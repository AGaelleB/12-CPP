#include <iostream>
#include "../includes/PhoneBook.hpp"
#include "../includes/Contact.hpp"

PhoneBook::PhoneBook(void) {
	std::cout << "Constructor PhoneBook called" << std::endl;
	return;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "*Destructor PhoneBook called*" << std::endl;
	return;
}
