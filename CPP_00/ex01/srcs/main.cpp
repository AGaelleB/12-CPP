#include <iostream>
#include <string>
#include <limits>
#include "../includes/PhoneBook.hpp"
#include "../includes/Contact.hpp"

int	main(void) {
	PhoneBook PhoneBook;
	std::string userInput;
	PhoneBook.OpenPhoneBook();
	while(1) {
		std::cout << "Enter your choice : ";
		std::getline(std::cin, userInput);
		if (std::cin.eof()) {// permet de ne pas faire de boucle infinie si ctrlD par ex
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
	return (0);
}
