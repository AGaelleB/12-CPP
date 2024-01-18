#include <iostream>
#include "../includes/PhoneBook.hpp"
#include "../includes/Contact.hpp"

PhoneBook::PhoneBook(void) {
	std::cout << "Constructor PhoneBook" << std::endl;
	return;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "Destructor PhoneBook" << std::endl;
	return;
}
