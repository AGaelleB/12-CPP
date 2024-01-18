#include <iostream>
#include "../includes/PhoneBook.hpp"
#include "../includes/Contact.hpp"

Contact::Contact(void) {
	std::cout << "Constructor Contact" << std::endl;
	return;
}

Contact::~Contact(void) {
	std::cout << "Destructor Contact" << std::endl;
	return;
}
