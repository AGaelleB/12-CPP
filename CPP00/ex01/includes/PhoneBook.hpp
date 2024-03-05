#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

#include "../includes/Contact.hpp"

class PhoneBook {

	private:
		Contact _PhoneBook[8];
		int _contactCount;
		int _nextIndex; 

	public:
		// appel des constructors et destructors
		PhoneBook(void);
		~PhoneBook(void);

		void OpenPhoneBook(void) const;
		void AddContact(void);
		void DataContact(Contact &newContact);
		void SearchContact(void);
		void DisplayAllContacts(void);
		void DisplayContactIndex(int userInput);
		void ExitContact(void);
};
// l’objet répertoire doit être une instance de la classe PhoneBook

#endif