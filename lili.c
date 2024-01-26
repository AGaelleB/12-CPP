je voudrais ajouter en paramettre de DisplayContactIndex l'index entree par l utilisateur. Puis en fonction de l index print le fistname de l utilisateur avec l index demande

class PhoneBook {

	private:
		Contact _PhoneBook[8];
		int _contactCount;

	public:
		// appel des constructor et destructor 
		PhoneBook(void);
		~PhoneBook(void);

		void OpenPhoneBook(void) const;
		void AddContact(void);
		void DataContact(Contact &newContact);
		void SearchContact(void);
		void DisplayAllContacts(void);
		void DisplayContactIndex(Contact &userInput);
		void ExitContact(void);
};

void PhoneBook::SearchContact(void) {

	std::cout << std::endl;
	std::cout << BLUE << "* * * * * * * Your Contacts * * * * * * * * *" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << " -------------------------------------------" << std::endl;
	std::cout << "|  index   | 1st name | lastname | nickname |" << std::endl;
	std::cout << " -------------------------------------------" << std::endl;
	DisplayAllContacts();

	return;
}

void PhoneBook::DisplayAllContacts(void) {
	// std::string userInput;
	Contact userInput;
	
	for (int i = 1; i < _contactCount; i++) {
		Contact &currentContact = _PhoneBook[i];
		std::cout << "|" << std::setw(10) << std::right << currentContact.getIndex() << "|";
		std::cout << "" << std::setw(10) << std::right << currentContact.getFirstName() << "|";
		std::cout << "" << std::setw(10) << std::right << currentContact.getLastName() << "|";
		std::cout << "" << std::setw(10) << std::right << currentContact.getNickname() << "|" << std::endl;
	}

	std::cout << std::endl;
	while (1) {
		std::cout << "Please enter the contact index : ";
		std::getline(std::cin, userInput);
		if (userInput >= "1" && userInput <= "8") {
			DisplayContactIndex(userInput);;
			break;
		} 
	}
}


void PhoneBook::DisplayContactIndex(Contact &userInput) {

    // print ici en fonction de l index
	return;
}
