#include <iostream>
#include <string>
#include <limits>
#include "../includes/PhoneBook.hpp"
#include "../includes/Contact.hpp"

int	main(int ac, char **av) {
	(void)av;

	if (ac != 1)
		std::cout << "1 argument needed" << std::endl;
	else {
		PhoneBook PhoneBook;
		std::string userInput;
		PhoneBook.OpenPhoneBook();
		while(1) {
			std::cout << "Enter your choice : ";
			std::getline(std::cin, userInput);
			if (std::cin.eof()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;
			}
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
	}
	return (0);
}
