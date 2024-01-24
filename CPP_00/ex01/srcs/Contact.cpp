#include <iostream>
#include <string>
#include "../includes/PhoneBook.hpp"
#include "../includes/Contact.hpp"

Contact::Contact(void) {
	std::cout << "Constructor Contact called" << std::endl;
	return;
}

Contact::~Contact(void) {
	std::cout << "*Destructor Contact called*" << std::endl;
	return;
}
