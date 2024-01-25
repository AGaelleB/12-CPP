#include <iostream>
#include <string>
#include "../includes/PhoneBook.hpp"
#include "../includes/Contact.hpp"

// Définissez des codes ANSI pour les couleurs
const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string BLUE = "\033[34m";
const std::string YELLOW = "\033[33m";

PhoneBook::PhoneBook(void) {
	// std::cout << "Constructor PhoneBook called" << std::endl;
	return;
}

PhoneBook::~PhoneBook(void) {
	// std::cout << "*Destructor PhoneBook called*" << std::endl;
	return;
}

void PhoneBook::OpenPhoneBook(void) const {
	std::cout << std::endl;
	std::cout << BLUE << "* * * * * * * * Your  PhoneBook * * * * * * * *" << RESET << std::endl;
	std::cout << BLUE << "*                                             *" << RESET << std::endl;
	std::cout << BLUE << "*" << GREEN << "  To add contact write \"""ADD""\"" << BLUE << "                 *" << RESET << std::endl;
	std::cout << BLUE << "*" << YELLOW << "  To search for a contact write \"""SEARCH""\"" << BLUE << "     *" << RESET << std::endl;
	std::cout << BLUE << "*" << RED << "  To exit write \"""EXIT""\"" << BLUE << "                       *" << RESET << std::endl;
	std::cout << BLUE << "*                                             *" << RESET << std::endl;
	std::cout << BLUE << "* * * * * * * * * * * * * * * * * * * * * * * *" << RESET << std::endl;
	std::cout << std::endl;

	return;
}

void PhoneBook::AddContact(void) {
	Contact newContact;
	std::string userInput;


	std::cout << BLUE << "* * * * * * * * * * * * * * * * * * * * * * * *" << RESET << std::endl;
	std::cout << "Enter your first name : ";
	std::cin >> userInput;
	newContact.setFirstName(userInput);

	std::cout << "Enter your last name : ";
	std::cin >> userInput;
	newContact.setLastName(userInput);

	std::cout << "Enter your nickname : ";
	std::cin >> userInput;
	newContact.setNickname(userInput);

	std::cout << "Enter your phone number : ";
	std::cin >> userInput;
	newContact.setPhoneNumber(userInput);

	std::cout << "Enter your darkest secret : ";
	std::cin.ignore();  // Ignorer les caractères restants du précédent std::cin, vider mémoire tampon
	std::getline(std::cin, userInput);  // Permet de ne pas s'arrêter si espaces
	newContact.setDarkestSecret(userInput);
	
	std::cout << BLUE << "* * * * * * * * * * * * * * * * * * * * * * * *" << RESET << std::endl;

	// Stocker le nouveau contact dans le tableau
	// Vous devrez implémenter une logique pour gérer l'ajout dans le tableau.
	// Par exemple, trouver la première position libre dans le tableau et y ajouter le contact.
}



void PhoneBook::SearchContact(void) {
	int userInput;
	Contact indexContact;

	std::cout << std::endl;
	std::cout << BLUE << "* * * * * * * Your Contacts * * * * * * * * *" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << " -------------------------------------------" << std::endl;
	std::cout << "|  index   | 1st name | lastname | nickname |" << std::endl;
	std::cout << " -------------------------------------------" << std::endl;

	std::cout << std::endl;
	std::cout << "Please enter the contact index : ";
	std::cin >> userInput;
	indexContact.setIndex(userInput);
	// int contactIndex = indexContact.getIndex();
	std::cout << std::endl;

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