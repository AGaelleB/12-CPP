#include <iostream>
#include <string>
#include "../includes/PhoneBook.hpp"
#include "../includes/Contact.hpp"

int	main(void) {
	PhoneBook PhoneBook;
	std::string userInput;
	PhoneBook.OpenPhoneBook();

	while(1) {
		std::cout << "Please enter your choice : ";
		std::cin >> userInput;

		if (userInput == "ADD") {
			std::cout << "You chose to add a contact." << std::endl;
		}
		else if (userInput == "SEARCH") {
			std::cout << "You chose to search." << std::endl;
		}
		else if (userInput == "EXIT") {
			std::cout << "You chose to exit, bye." << std::endl;
			break;
		}
		else {
			std::cout << std::endl;
			std::cout << "Invalid choice, please choose between \"ADD\", \"SEARCH\" and \"EXIT\"" << std::endl;
			std::cout << std::endl;
		}
	}
	return (0);
}
