#include <iostream>
#include <string>
#include "../includes/PhoneBook.hpp"
#include "../includes/Contact.hpp"

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string BLUE = "\033[34m";
const std::string YELLOW = "\033[33m";

int	main(void) {
	int i = 0;
	PhoneBook PhoneBook;
	std::string userInput;
	PhoneBook.OpenPhoneBook();
	while(1) {
		std::cout << "Enter your choice : ";
		std::getline(std::cin, userInput);
		if (userInput == "ADD") {
			if (i < 8)
			{
				PhoneBook.AddContact();
				std::cout << "You've added " << ++i << " / 8 contacts." << std::endl;
			}
			else 
				std::cout << "Your PhoneBook is full. You can't add more contacts sorry." << std::endl;
		}
		else if (userInput == "SEARCH") {
			// std::cout << "You chose to search." << std::endl;
			PhoneBook.SearchContact();
		}
		else if (userInput == "EXIT") {
			std::cout << "You chose to exit, bye." << std::endl;
			break;
		}
		else {
			// std::cout << RED << "           /!\\   Invalid choice   /!\\" << RESET << std::endl;
			// std::cout << "Please choose between : \"ADD\", \"SEARCH\" and \"EXIT\"" << std::endl;
			// std::cout << std::endl;
		}
	}
	return (0);
}
