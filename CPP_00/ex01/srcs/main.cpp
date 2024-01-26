#include <iostream>
#include <string>
#include "../includes/PhoneBook.hpp"
#include "../includes/Contact.hpp"

int	main(void) {
	PhoneBook PhoneBook;
	std::string userInput;
	PhoneBook.OpenPhoneBook();
	while(1) {
		std::cout << "Enter your choice : ";
		std::getline(std::cin, userInput);
		if (userInput == "ADD")
			PhoneBook.AddContact();
		else if (userInput == "SEARCH") {
			PhoneBook.SearchContact();
			std::cin.ignore();
		}
		else if (userInput == "EXIT") {
			PhoneBook.ExitContact();
			break;
		}
	}
	return (0);
}
